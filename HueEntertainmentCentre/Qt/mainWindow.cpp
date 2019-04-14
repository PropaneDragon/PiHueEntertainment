#include <QShowEvent>
#include <QMessageBox>
#include <QTimer>

#include "huestream/HueStream.h"
#include "huestream/effect/effects/AreaEffect.h"
#include "huestream/effect/animation/animations/SequenceAnimation.h";
#include "huestream/effect/animation/animations/TweenAnimation.h";

#include "Hue/bridgeConnectionHandlerInstance.h"
#include "Hue/colourArea.h"

#include "cameraCapture.h"
#include "entertainmentGroupConnectDialog.h"
#include "hubConnectDialog.h"
#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags f) : QMainWindow(parent, f)
{
	setupUi(this);

	_capture = new CameraCapture(this);
	_captureTimer = new QTimer(this);
	_captureTimer->setInterval(10);

	connect(_captureTimer, &QTimer::timeout, this, &MainWindow::captureTimerUpdated);
}

void MainWindow::showEvent(QShowEvent *event)
{
	if (event->type() == QShowEvent::Type::Show) {
		auto timer = new QTimer(this);
		timer->setSingleShot(true);
		timer->setInterval(1000);
		
		connect(timer, &QTimer::timeout, [this]() {
			connectToBridge();
		});

		timer->start();
	}
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	disconnectFromBridge();
	disconnectFromCamera();
}

void MainWindow::onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge)
{
	_stream = stream;

	auto groups = bridge->GetGroups();
	if (!groups || groups->size() <= 0) {
		
		auto selectedButton = QMessageBox::critical(this, "No entertainment areas found", "It appears that there are no entertainment areas set up on this hub.\n\nPlease make sure you have at least one entertainment area set up in the Hue app before connecting again.", QMessageBox::StandardButton::Retry | QMessageBox::StandardButton::Ok);
		if (selectedButton != QMessageBox::StandardButton::Retry) {
			stream->ResetBridgeInfo();
		}

		connectToBridge();
	}
	else if (groups->size() == 1) {
		connectToGroup(*(groups->begin()));
	}
	else {
		auto groupSelectionDialog = new EntertainmentGroupConnectDialog(*groups, this);
		auto result = (QDialog::DialogCode)groupSelectionDialog->exec();

		if (result == QDialog::DialogCode::Accepted) {

			auto selectedGroup = groupSelectionDialog->getSelectedGroup();
			if (selectedGroup) {
				connectToGroup(selectedGroup);
			}
		}
	}
}

void MainWindow::onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge)
{
	QMessageBox::critical(this, "Bridge disconnected", "The connection to the bridge appears to have been lost.");
}

void MainWindow::onBridgeConnectionFailed()
{
	QMessageBox::critical(this, "Couldn't connect to the bridge", "A connection to the bridge could not be established.");
}

void MainWindow::connectToGroup(std::shared_ptr<huestream::Group> group)
{
	if (group && _stream) {
		_stream->SelectGroup(group);

		connectToCamera();
	}
}

void MainWindow::processImage(const QImage &image)
{
	if (!image.isNull() && _stream) {

		auto transformedImage = image;		
		auto centre = transformedImage.rect().center();
			
		QMatrix rotationMatrix;
		rotationMatrix.translate(centre.x(), centre.y());
		rotationMatrix.rotate(_imageRotation);
		rotationMatrix.scale(_imageFlippedVertically ? -1 : 1, _imageFlippedHorizontally ? -1 : 1);

		transformedImage = transformedImage.transformed(rotationMatrix, Qt::TransformationMode::FastTransformation);

		auto size = transformedImage.size();

		std::vector<ColourArea> areas = {
			ColourArea(_capture, { huestream::Area::Left, huestream::Area::FrontLeft, huestream::Area::BackLeft, huestream::Area::CenterLeft }, Area(0, 0, 25, 0)),
			ColourArea(_capture, { huestream::Area::Right, huestream::Area::FrontRight, huestream::Area::BackRight, huestream::Area::CenterRight }, Area(0, 75, 0, 0)),
			ColourArea(_capture, { huestream::Area::Center, huestream::Area::FrontCenter, huestream::Area::BackCenter }, Area(10, 15, 15, 10)),
		};

		for (auto y = 0; y < size.height(); ++y) {
			for (auto x = 0; x < size.width(); ++x) {
				auto pixelColour = transformedImage.pixelColor(QPoint(x, y));

				for (auto area : areas) {
					if (area.pointIsInside(x, y)) {
						area.getColourGroup()->addColour(pixelColour);
					}
				}
			}
		}

		_stream->LockMixer();

		for (auto area : areas) {
			auto average = area.getColourGroup()->getAverage();
			auto colour = average.hueColour();
			auto effect = std::make_shared<huestream::AreaEffect>();

			effect->SetAreas(std::make_shared<huestream::AreaList>(area.getAreas()));
			effect->SetFixedColor(colour);
			_stream->AddEffect(effect);
			effect->Enable();
		}

		_stream->UnlockMixer();

		if (_imageAllowedToUpdate) {
			label_cameraImage->setPixmap(QPixmap::fromImage(transformedImage));
		}
	}
}

void MainWindow::captureTimerUpdated()
{
	if (!_capture->connectedToCamera()) {
		_captureTimer->stop();

		if (!_capture->wasSafelyDisconnected()) {
			QMessageBox::critical(this, "Couldn't connect to the camera", "The camera cannot be accessed anymore. This could be due to the camera becoming unplugged, or another application is using it.");
		}
	}
	else if (!_stream)	{
		_captureTimer->stop();
	}
	else {
		auto frameTime = (int)std::round(1000.0 / _targetFramerate);
		_captureTimer->setInterval(frameTime);

		if (_capture->hasNewImage(_lastRequestTime) && _stream) {
			
			_lastRequestTime = QDateTime::currentDateTime();

			auto image = _capture->lastImage();
			if (!image.isNull()) {

				processImage(image);
			}
		}
	}
}

void MainWindow::connectToBridge()
{
	disconnectFromBridge();

	if (!_stream || !_stream->IsBridgeStreaming()) {
		auto connectDialog = new HubConnectDialog(this);
		auto result = (QDialog::DialogCode)connectDialog->exec();
	}
}

void MainWindow::connectToCamera()
{
	disconnectFromCamera();

	auto retry = true;
	while (retry) {
		retry = false;
		_capture->connectToDefaultCamera();
		if (_capture->connectedToCamera()) {
			_captureTimer->start();
		}
		else {
			auto selectedButton = QMessageBox::critical(this, "Couldn't find a camera", "A compatible camera couldn't be found, or the default camera is unavailable.\n\nPlease ensure a camera is plugged in, or the default camera is not currently in use and try again.", QMessageBox::StandardButton::Retry | QMessageBox::StandardButton::Ok);
			retry = selectedButton == QMessageBox::StandardButton::Retry;
		}
	}
}

void MainWindow::connectToNewBridge()
{
	_stream->ResetBridgeInfo();

	connectToBridge();
}

void MainWindow::connectToNewCamera()
{
	connectToCamera();
}

void MainWindow::disconnectFromBridge()
{
	if (_stream && _stream->IsBridgeStreaming()) {
		_stream->Stop();
	}
}

void MainWindow::disconnectFromCamera()
{
	_capture->disconnectCamera();
}

void MainWindow::changeImageUpdatePreference(bool canUpdate)
{
	_imageAllowedToUpdate = canUpdate;
}

void MainWindow::rotateImageClockwise()
{
	rotateImage(90);
}

void MainWindow::rotateImageAntiClockwise()
{
	rotateImage(-90);
}

void MainWindow::flipImageHorizontal(bool flip)
{
	_imageFlippedHorizontally = flip;
}

void MainWindow::flipImageVertical(bool flip)
{
	_imageFlippedVertically = flip;
}

void MainWindow::rotateImage(int degrees)
{
	auto newRotation = _imageRotation + degrees;
	
	while (newRotation >= 360) {
		newRotation -= 360;
	}

	while (newRotation < 0) {
		newRotation += 360;
	}

	_imageRotation = newRotation;
}

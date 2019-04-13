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

void MainWindow::connectToBridge()
{
	if (!_connected) {
		auto connectDialog = new HubConnectDialog(this);
		auto result = (QDialog::DialogCode)connectDialog->exec();

		if (result == QDialog::DialogCode::Accepted) {
			_connected = true;
		}
	}
}

void MainWindow::onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge)
{
	_stream = stream;

	auto groups = bridge->GetGroups();
	if (!groups || groups->size() <= 0) {
		
		auto selectedButton = QMessageBox::critical(this, "No entertainment groups found", "It appears that there are no entertainment groups set up on this hub.\n\nPlease make sure you have at least one entertainment group before connecting again.", QMessageBox::StandardButton::Retry | QMessageBox::StandardButton::Ok);
		if (selectedButton != QMessageBox::StandardButton::Retry) {
			stream->ResetBridgeInfo();
		}

		_connected = false;

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
}

void MainWindow::onBridgeConnectionFailed()
{
}

void MainWindow::connectToGroup(std::shared_ptr<huestream::Group> group)
{
	if (group && _stream) {
		_stream->SelectGroup(group);

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
}

void MainWindow::processImage(const QImage & image)
{
	if (!image.isNull()) {
		auto size = image.size();
		auto areas = std::vector<ColourArea>{
			ColourArea(_capture, { huestream::Area::Left, huestream::Area::FrontLeft, huestream::Area::BackLeft, huestream::Area::CenterLeft }, Area(0, 0, 25, 0)),
			ColourArea(_capture, { huestream::Area::Right, huestream::Area::FrontRight, huestream::Area::BackRight, huestream::Area::CenterRight }, Area(0, 75, 0, 0)),
			ColourArea(_capture, { huestream::Area::Center, huestream::Area::FrontCenter, huestream::Area::BackCenter }, Area(10, 15, 15, 10)),
		};

		for (auto y = 0; y < size.height(); ++y) {
			for (auto x = 0; x < size.width(); ++x) {
				auto pixelColour = image.pixelColor(QPoint(x, y));

				for (auto area : areas) {
					if (area.pointIsInside(x, y)) {
						area.getColourGroup()->addColour(pixelColour);
					}
					else {
						int a = 0;
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
	}
}

void MainWindow::captureTimerUpdated()
{
	if (!_capture->connectedToCamera()) {
		_captureTimer->stop();
	}
	else {
		auto frameTime = (int)std::round(1000.0 / _targetFramerate);
		_captureTimer->setInterval(frameTime);

		if (_capture->hasNewImage(_lastRequestTime) && _stream) {
			
			_lastRequestTime = QDateTime::currentDateTime();

			auto image = _capture->lastImage();
			if (!image.isNull()) {

				label_cameraImage->setPixmap(QPixmap::fromImage(image));

				processImage(image);
			}
		}
	}
}

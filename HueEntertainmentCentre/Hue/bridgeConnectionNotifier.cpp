#include <iostream>

#include <QWidget>
#include <QTimer>
#include <QLabel>

#include "huestream/effect/effects/AreaEffect.h"
#include "huestream/effect/animation/animations/SequenceAnimation.h";
#include "huestream/effect/animation/animations/TweenAnimation.h";

#include "colourGroup.h"
#include "colourArea.h"
#include "bridgeConnectionNotifier.h"

BridgeConnectionNotifier::BridgeConnectionNotifier()
{
}

void BridgeConnectionNotifier::onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge)
{
	_capture = std::shared_ptr<CameraCapture>(new CameraCapture());

	/*if (bridge && stream) {
		std::cout << "Connected to bridge " + bridge->GetName() + " at IP " + bridge->GetIpAddress() + "." << std::endl;
		
		auto groups = bridge->GetGroups();
		for (auto group : *groups) {
			std::cout << group->GetName() + " group found." << std::endl;
		}

		if (groups->size() <= 0) {
			std::cout << "No streamable groups found. Please set up your Entertainment Areas in the Hue app." << std::endl;

			_requestedGroupIndex = -1;
		}
		else if (groups->size() > 1) {
			std::cout << "Multiple groups found. Connecting to the requested group..." << std::endl;
		}
		else {
			std::cout << "One group found. Connecting..." << std::endl;
		}

		if (_requestedGroupIndex >= 0 && _requestedGroupIndex < groups->size()) {
			
			auto chosenGroup = groups->at(_requestedGroupIndex);
			if (chosenGroup) {
				startGroup(chosenGroup, stream);
			}
		}
	}
	else {
		std::cout << "Connected to a null bridge or has a null stream" << std::endl;
	}*/
}

void BridgeConnectionNotifier::onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge)
{
	if (bridge) {
		std::cout << "Disconnected from bridge " + bridge->GetName() << std::endl;
	}
	else {
		std::cout << "Disconnected from null bridge" << std::endl;
	}
}

void BridgeConnectionNotifier::onBridgeConnectionFailed()
{
	std::cout << "Failed to connect to a bridge." << std::endl;
}

void BridgeConnectionNotifier::setUpdateImage(QLabel *image)
{
	_updateImage = image;
}

void BridgeConnectionNotifier::setTargetFramerate(int framesPerSecond)
{
	_targetFramerate = framesPerSecond;
}

int BridgeConnectionNotifier::getTargetFramerate() const
{
	return _targetFramerate;
}

std::shared_ptr<huestream::Bridge> BridgeConnectionNotifier::getHueBridge() const
{
	return _bridge;
}

std::shared_ptr<huestream::IHueStream> BridgeConnectionNotifier::getHueStream() const
{
	return _stream;
}

void BridgeConnectionNotifier::startGroup(std::shared_ptr<huestream::Group> group, std::shared_ptr<huestream::IHueStream> stream)
{
	/*stream->SelectGroup(group);

	_capture->connectToDefaultCamera();

	if (_capture->connectedToCamera()) {
		auto updateTimer = new QTimer();
		auto frameTime = (int)std::round(1000.0 / _targetFramerate);
		auto animationTime = frameTime / 10.0;

		updateTimer->setInterval(frameTime);
		
		QObject::connect(updateTimer, &QTimer::timeout, [this, stream, animationTime]() {

			if (_capture->hasNewImage(_lastRequestTime) && stream) {
				auto image = _capture->lastImage();

				if (!image.isNull()) {
					auto size = image.size();
					auto areas = std::vector<ColourArea> {
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

					stream->LockMixer();

					for (auto area : areas) {
						auto average = area.getColourGroup()->getAverage();
						auto colour = average.hueColour();
						auto effect = std::make_shared<huestream::AreaEffect>();

						effect->SetAreas(std::make_shared<huestream::AreaList>(area.getAreas()));
						effect->SetFixedColor(colour);
						stream->AddEffect(effect);
						effect->Enable();
					}

					stream->UnlockMixer();

					if (_updateImage) {
						_updateImage->setPixmap(QPixmap::fromImage(image));
					}
				}
			}
		});

		updateTimer->start();
	}
	else {
		auto effect = std::make_shared<huestream::AreaEffect>();
		effect->SetFixedColor(huestream::Color(1.0, 0.2, 0.2));
		effect->SetArea(huestream::Area::All);

		stream->LockMixer();
		stream->AddEffect(effect);
		effect->Enable();
		stream->UnlockMixer();
	}

	std::cout << "Connected!" << std::endl;*/
}

#include <iostream>

#include <QWidget>
#include <QTimer>
#include <QLabel>

#include "huestream/effect/effects/AreaEffect.h"
#include "huestream/effect/animation/animations/SequenceAnimation.h";
#include "huestream/effect/animation/animations/TweenAnimation.h";

#include "colourGroup.h"
#include "bridgeConnectionNotifier.h"

BridgeConnectionNotifier::BridgeConnectionNotifier()
{
}

void BridgeConnectionNotifier::onBridgeConnected(huestream::HueStreamPtr stream, huestream::BridgePtr bridge)
{
	_capture = std::unique_ptr<CameraCapture>(new CameraCapture());

	if (bridge && stream) {
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
	}
}

void BridgeConnectionNotifier::onBridgeDisconnected(huestream::BridgePtr bridge)
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

void BridgeConnectionNotifier::startGroup(huestream::GroupPtr group, huestream::HueStreamPtr stream)
{
	std::cout << "Connecting to group " + group->GetName() + "." << std::endl;

	stream->SelectGroup(group);

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
					auto colours = ColourGroup();

					for (auto y = 0; y < size.height(); ++y) {
						for (auto x = 0; x < size.width(); ++x) {
							auto pixelColour = image.pixelColor(QPoint(x, y));
							colours.addColour(pixelColour);
						}
					}

					auto average = colours.getAverage();

					auto differenceR = std::abs(average.getRed() - _lastColour.getRed());
					auto differenceG = std::abs(average.getGreen() - _lastColour.getGreen());
					auto differenceB = std::abs(average.getBlue() - _lastColour.getBlue());

					if (differenceR > _smoothingLevel || differenceG > _smoothingLevel || differenceB > _smoothingLevel) {
						auto colour = average.hueColour();
						auto effect = std::make_shared<huestream::AreaEffect>();

						effect->SetArea(huestream::Area::All);
						effect->SetFixedColor(colour);

						stream->LockMixer();
						stream->AddEffect(effect);
						effect->Enable();
						stream->UnlockMixer();
					}

					_lastColour = average;

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

	std::cout << "Connected!" << std::endl;
}

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

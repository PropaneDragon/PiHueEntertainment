#pragma once

#include <QDateTime>

#include "../Qt/cameraCapture.h"

#include "colour.h"
#include "abstractBridgeConnectionNotifier.h"

class QLabel;
class BridgeConnectionNotifier : public AbstractBridgeConnectionNotifier
{
public:
	BridgeConnectionNotifier();

	virtual void onBridgeConnected(huestream::HueStreamPtr stream, huestream::BridgePtr bridge) override;
	virtual void onBridgeDisconnected(huestream::BridgePtr bridge) override;
	virtual void onBridgeConnectionFailed() override;

	void setUpdateImage(QLabel *image);

protected:
	void startGroup(huestream::GroupPtr group, huestream::HueStreamPtr stream);

private:
	int _requestedGroupIndex = 2;
	int _targetFramerate = 15;
	QDateTime _lastRequestTime = QDateTime::currentDateTime();

	QLabel *_updateImage = nullptr;

	std::shared_ptr<CameraCapture> _capture = nullptr;
};
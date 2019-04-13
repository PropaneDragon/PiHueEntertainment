#pragma once

#include <QDateTime>

#include "Qt/cameraCapture.h"

#include "colour.h"
#include "abstractBridgeConnectionNotifier.h"

class QLabel;
class BridgeConnectionNotifier : public AbstractBridgeConnectionNotifier
{
public:
	BridgeConnectionNotifier();

	virtual void onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge) override;
	virtual void onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge) override;
	virtual void onBridgeConnectionFailed() override;

	void setUpdateImage(QLabel *image);
	void setTargetFramerate(int framesPerSecond);

	int getTargetFramerate() const;

	std::shared_ptr<huestream::Bridge> getHueBridge() const;
	std::shared_ptr<huestream::IHueStream> getHueStream() const;

protected:
	void startGroup(std::shared_ptr<huestream::Group> group, std::shared_ptr<huestream::IHueStream> stream);

private:
	int _requestedGroupIndex = 0;
	int _targetFramerate = 10;

	QDateTime _lastRequestTime = QDateTime::currentDateTime();
	QLabel *_updateImage = nullptr;

	std::shared_ptr<CameraCapture> _capture = nullptr;
	std::shared_ptr<huestream::Bridge> _bridge = nullptr;
	std::shared_ptr<huestream::IHueStream> _stream = nullptr;
};
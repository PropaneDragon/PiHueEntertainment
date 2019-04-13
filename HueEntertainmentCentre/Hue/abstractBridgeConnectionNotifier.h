#pragma once

namespace huestream
{
	class IHueStream;
	class Bridge;
}

class AbstractBridgeConnectionNotifier
{
public:
	AbstractBridgeConnectionNotifier() {};
	virtual ~AbstractBridgeConnectionNotifier() {};

	virtual void onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge) {};
	virtual void onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge) {};
	virtual void onBridgeConnectionFailed() {};

private:

};
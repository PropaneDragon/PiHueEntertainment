#pragma once

#include "huestream/HueStream.h"

class AbstractBridgeConnectionNotifier
{
public:
	AbstractBridgeConnectionNotifier() {};
	virtual ~AbstractBridgeConnectionNotifier() {};

	virtual void onBridgeConnected(huestream::HueStreamPtr stream, huestream::BridgePtr bridge) {};
	virtual void onBridgeDisconnected(huestream::BridgePtr bridge) {};
	virtual void onBridgeConnectionFailed() {};

private:

};
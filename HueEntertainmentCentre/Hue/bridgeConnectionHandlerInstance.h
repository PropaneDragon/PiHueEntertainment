#pragma once

#include "bridgeConnectionHandler.h"

class BridgeConnectionHandlerInstance
{
public:
	static BridgeConnectionHandler *Instance();

private:
	static BridgeConnectionHandler *_instance;

};
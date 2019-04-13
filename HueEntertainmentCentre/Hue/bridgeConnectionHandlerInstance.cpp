#include "bridgeConnectionHandlerInstance.h"

BridgeConnectionHandler* BridgeConnectionHandlerInstance::_instance = nullptr;

BridgeConnectionHandler* BridgeConnectionHandlerInstance::Instance()
{
	if (!_instance) {
		_instance = new BridgeConnectionHandler("Pi Camera Mirror");
	}

	return _instance;
}

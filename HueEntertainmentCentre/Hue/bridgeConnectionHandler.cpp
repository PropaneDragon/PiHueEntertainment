#include "bridgeConnectionHandler.h"

BridgeConnectionHandler::BridgeConnectionHandler(const std::string &applicationName)
{
	_config = std::shared_ptr<huestream::Config>(new huestream::Config(applicationName, "Hardware", huestream::PersistenceEncryptionKey("92C5FFFA-7B90-40A6-B6C4-6F04FFA7466E")));
	_stream = std::shared_ptr<huestream::HueStream>(new huestream::HueStream(_config));
}

void BridgeConnectionHandler::setNotifier(std::shared_ptr<AbstractBridgeConnectionNotifier> notifier)
{
	_notifier = notifier;
}

bool BridgeConnectionHandler::tryConnect()
{
	if (_stream) {
		_stream->ConnectBridge();

		auto activeBridge = _stream->GetActiveBridge();
		auto connected = activeBridge != nullptr && activeBridge->IsConnected();

		if (_notifier) {
			if (connected) {
				_notifier->onBridgeConnected(_stream, activeBridge);
			}
			else {
				_notifier->onBridgeConnectionFailed();
			}
		}

		return connected;
	}

	return false;
}

bool BridgeConnectionHandler::disconnect()
{
	if (_stream && _stream->IsBridgeStreaming()) {
		
		_stream->Stop();

		return true;
	}

	return false;
}
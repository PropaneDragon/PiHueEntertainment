#pragma once

#include <string>
#include <memory>

#include "huestream/HueStream.h"

#include "abstractBridgeConnectionNotifier.h"

class BridgeConnectionHandler
{
public:
	BridgeConnectionHandler(const std::string &applicationName);

	void setNotifier(std::shared_ptr<AbstractBridgeConnectionNotifier> notifier);

	bool tryConnect();
	bool disconnect();

private:
	std::shared_ptr<AbstractBridgeConnectionNotifier> _notifier = nullptr;
	std::shared_ptr<huestream::Config> _config = nullptr;
	std::shared_ptr<huestream::HueStream> _stream = nullptr;
};
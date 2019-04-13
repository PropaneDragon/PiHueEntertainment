#pragma once

#include <string>
#include <vector>
#include <memory>

#include "huestream/HueStream.h"

#include "abstractBridgeConnectionNotifier.h"

class BridgeConnectionHandler
{
public:
	BridgeConnectionHandler(const std::string &applicationName);

	void setNotifier(std::shared_ptr<AbstractBridgeConnectionNotifier> notifier);
	void checkConnectionAndNotify();

	bool tryConnect();
	bool tryConnectAndNotify();
	bool disconnect();

	std::vector<std::shared_ptr<huestream::Bridge>> getAvailableBridges();

private:
	std::shared_ptr<AbstractBridgeConnectionNotifier> _notifier = nullptr;
	std::shared_ptr<huestream::Config> _config = nullptr;
	std::shared_ptr<huestream::HueStream> _stream = nullptr;
};
#include "monitoring.h"

Monitoring* Monitoring::_instance = nullptr;

Monitoring::Monitoring()
{
}

Monitoring::~Monitoring()
{
	delete _rootTiming;
	_rootTiming = nullptr;
}

Monitoring* Monitoring::Instance()
{
	if (!_instance) {
		_instance = new Monitoring();
	}

	return _instance;
}

void Monitoring::begin(const std::string &name)
{
	auto runningChild = _rootTiming->getNextRunningChild();
	if (!runningChild) {
		runningChild = _rootTiming;
	}

	auto newTiming = runningChild->getChild(name);
	if (!newTiming) {
		newTiming = runningChild->add(name);
	}

	newTiming->start();
}

void Monitoring::end()
{
	auto runningChild = _rootTiming->getNextRunningChild();
	if (runningChild) {
		runningChild->stop();
	}
}

Timing* Monitoring::getRoot() const
{
	return _rootTiming;
}

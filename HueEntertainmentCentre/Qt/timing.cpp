#include <algorithm>

#include "timing.h"

Timing::Timing(const std::string &name, Timing *parent)
{
	_name = name;

	setParent(parent);
}

Timing::~Timing()
{
	for (auto child : _children) {
		delete child;
	}

	_children.clear();
}

void Timing::start()
{
	_finished = false;
	_startTime = std::chrono::steady_clock::now();
}

void Timing::stop()
{
	_executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _startTime);
	_finished = true;
}

void Timing::setParent(Timing *parent)
{
	_parent = parent;
}

bool Timing::hasFinished() const
{
	return _finished;
}

bool Timing::hasChild(const std::string &name, bool searchGrandchildren) const
{
	return getChild(name, searchGrandchildren) != nullptr;
}

int64_t Timing::getMilliseconds() const
{
	if (hasFinished()) {
		return _executionTime.count();
	}

	return 0;
}

std::string Timing::getName() const
{
	return _name;
}

std::vector<Timing*> Timing::getChildren() const
{
	return _children;
}

Timing* Timing::add(const std::string &name)
{
	auto timing = new Timing(name, this);

	_children.push_back(timing);

	timing->start();

	return timing;
}

Timing* Timing::getParent() const
{
	return _parent;
}

Timing* Timing::getNextRunningChild() const
{
	auto foundRunning = std::find_if(_children.rbegin(), _children.rend(), [](Timing *child) {
		return !child->hasFinished();
	});

	if (foundRunning != _children.rend()) {
		auto runningChild = *foundRunning;
		auto childOfChild = runningChild->getNextRunningChild();

		if (!childOfChild) {
			return runningChild;
		}
		else {
			return childOfChild;
		}
	}

	return nullptr;
}

Timing* Timing::getChild(const std::string &name, bool searchGrandchildren) const
{
	for (auto child : _children) {
		if (child->getName() == name) {
			return child;
		}
		else if (searchGrandchildren) {
			auto grandchild = child->getChild(name, searchGrandchildren);
			if (grandchild) {
				return grandchild;
			}
		}
	}

	return nullptr;
}
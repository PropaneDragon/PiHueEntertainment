#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <memory>

class Timing
{
public:
	Timing(const std::string &name, Timing *parent = nullptr);
	~Timing();

	void start();
	void stop();
	void setParent(Timing *parent);

	bool hasFinished() const;
	bool hasChild(const std::string &name, bool searchGrandchildren = false) const;

	int64_t getMilliseconds() const;

	std::string getName() const;
	std::vector<Timing*> getChildren() const;

	Timing* add(const std::string &name);
	Timing* getParent() const;
	Timing* getNextRunningChild() const;
	Timing* getChild(const std::string &name, bool searchGrandchildren = false) const;

private:
	bool _finished = false;

	std::string _name = "";
	std::vector<Timing*> _children;

	std::chrono::time_point<std::chrono::steady_clock> _startTime = std::chrono::steady_clock::now();
	std::chrono::milliseconds _executionTime;

	Timing *_parent = nullptr;
};
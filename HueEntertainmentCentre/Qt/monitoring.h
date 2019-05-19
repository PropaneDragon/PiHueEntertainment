#pragma once

#include <string>
#include <memory>

#include "timing.h"

class Monitoring
{
public:
	Monitoring();
	~Monitoring();

	static Monitoring* Instance();

	void begin(const std::string &name);
	void end();

	Timing *getRoot() const;

private:
	static Monitoring *_instance;

	Timing* _rootTiming = new Timing("Root");
};
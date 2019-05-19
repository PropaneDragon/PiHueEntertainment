#pragma once

#include <vector>
#include <deque>

#include "colour.h"

class ColourGroup
{
public:
	ColourGroup(const std::vector<Colour> &colours = {});

	void reset();
	void addColour(const Colour &colour);

	int getSnappingLevel();
	int getSmoothingLevel();

	Colour getAverage();

private:
	int _count = 0;
	float _red = 0, _green = 0, _blue = 0;

	Colour _lastAverage;

	std::deque<Colour> _history;
};
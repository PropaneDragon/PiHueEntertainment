#pragma once

#include <vector>

#include "colour.h"

class ColourGroup
{
public:
	ColourGroup(const std::vector<Colour> &colours = {});

	void addColour(const Colour &colour);

	Colour getAverage() const;

private:
	int _count = 0;
	float _red = 0, _green = 0, _blue = 0;
};
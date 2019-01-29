#include <numeric>

#include "colourGroup.h"

ColourGroup::ColourGroup(const std::vector<Colour>& colours)
{
	for (auto colour : colours) {
		addColour(colour);
	}
}

void ColourGroup::addColour(const Colour &colour)
{
	_red += colour.getRed();
	_green += colour.getGreen();
	_blue += colour.getBlue();

	++_count;
}

Colour ColourGroup::getAverage() const
{
	float averageRed = 0, averageGreen = 0, averageBlue = 0;

	if (_count > 0) {
		averageRed = _red / _count;
		averageGreen = _green / _count;
		averageBlue = _blue / _count;
	}

	return Colour(averageRed, averageGreen, averageBlue);
}

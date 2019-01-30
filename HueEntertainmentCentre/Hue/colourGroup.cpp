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

Colour ColourGroup::getAverage()
{
	float averageRed = 0, averageGreen = 0, averageBlue = 0;

	if (_count > 0) {
		averageRed = _red / _count;
		averageGreen = _green / _count;
		averageBlue = _blue / _count;
	}

	Colour average(averageRed, averageGreen, averageBlue);

	auto differenceR = std::abs(average.getRed() - _lastAverage.getRed());
	auto differenceG = std::abs(average.getGreen() - _lastAverage.getGreen());
	auto differenceB = std::abs(average.getBlue() - _lastAverage.getBlue());

	if (differenceR > _smoothingLevel || differenceG > _smoothingLevel || differenceB > _smoothingLevel) {

		_lastAverage = average;
		return average;
	}

	return _lastAverage;
}

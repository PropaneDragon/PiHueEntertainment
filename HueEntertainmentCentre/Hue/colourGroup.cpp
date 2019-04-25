#include <numeric>

#include <QSettings>

#include "colourGroup.h"

ColourGroup::ColourGroup(const std::vector<Colour>& colours)
{
	for (auto colour : colours) {
		addColour(colour);
	}
}

void ColourGroup::reset()
{
	auto historyCount = getSmoothingLevel();

	while (historyCount >= 0 && _history.size() > historyCount) {
		_history.pop_back();
	}

	_history.push_front(_lastAverage);

	_red = 0;
	_green = 0;
	_blue = 0;
	_count = 0;
}

void ColourGroup::addColour(const Colour &colour)
{
	_red += colour.getRed();
	_green += colour.getGreen();
	_blue += colour.getBlue();

	++_count;
}

int ColourGroup::getSnappingLevel()
{
	QSettings settings;	
	return settings.value("processing/snapping", 0).toInt();
}

int ColourGroup::getSmoothingLevel()
{
	QSettings settings;
	return settings.value("processing/smoothing", 0).toInt();
}

Colour ColourGroup::getAverage()
{
	auto snappingLevel = getSnappingLevel() / (float)100;
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

	if (differenceR > snappingLevel || differenceG > snappingLevel || differenceB > snappingLevel) {
		_lastAverage = average;
	}

	std::vector<Colour> _averageFullColours{ _lastAverage };

	for (auto historyColour : _history) {
		_averageFullColours.push_back(historyColour);
	}

	return Colour::average(_averageFullColours);
}

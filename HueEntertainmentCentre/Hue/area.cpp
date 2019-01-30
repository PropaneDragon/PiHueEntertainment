#include "area.h"

Area::Area(int topPercentage, int leftPercentage, int rightPercentage, int bottomPercentage)
{
	setTopPercentage(topPercentage);
	setLeftPercentage(leftPercentage);
	setRightPercentage(rightPercentage);
	setBottomPercentage(bottomPercentage);
}

Area::~Area()
{
}

void Area::setTopPercentage(int topPercentage)
{
	_topPercentage = clamp(topPercentage);
}

void Area::setLeftPercentage(int leftPercentage)
{
	_leftPercentage = clamp(leftPercentage);
}

void Area::setRightPercentage(int rightPercentage)
{
	_rightPercentage = clamp(rightPercentage);
}

void Area::setBottomPercentage(int bottomPercentage)
{
	_bottomPercentage = clamp(bottomPercentage);
}

int Area::getTopPercentage() const
{
	return _topPercentage;
}

int Area::getLeftPercentage() const
{
	return _leftPercentage;
}

int Area::getRightPercentage() const
{
	return _rightPercentage;
}

int Area::getBottomPercentage() const
{
	return _bottomPercentage;
}

int Area::getWidthPercentage() const
{
	return (100 - getRightPercentage()) - getLeftPercentage();
}

int Area::getHeightPercentage() const
{
	return (100 - getBottomPercentage()) - getTopPercentage();
}

int Area::clamp(int number, int min, int max)
{
	return (number < min ? min : (number > max ? max : number));
}

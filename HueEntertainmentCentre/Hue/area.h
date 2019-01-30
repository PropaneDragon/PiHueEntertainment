#pragma once

class Area
{
public:
	Area(int topPercentage = 0, int leftPercentage = 0, int rightPercentage = 0, int bottomPercentage = 0);
	~Area();

	void setTopPercentage(int topPercentage);
	void setLeftPercentage(int leftPercentage);
	void setRightPercentage(int rightPercentage);
	void setBottomPercentage(int bottomPercentage);

	int getTopPercentage() const;
	int getLeftPercentage() const;
	int getRightPercentage() const;
	int getBottomPercentage() const;
	int getWidthPercentage() const;
	int getHeightPercentage() const;

private:
	int _topPercentage = 0;
	int _leftPercentage = 0;
	int _rightPercentage = 0;
	int _bottomPercentage = 0;

	int clamp(int number, int min = 0, int max = 100);
};
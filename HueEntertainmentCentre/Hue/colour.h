#pragma once

#include <vector>

#include <QColor>

#include "huestream/HueStream.h"

class Colour
{
public:
	Colour(float r = 0, float g = 0, float b = 0);
	Colour(const QColor &colour);
	Colour(const huestream::Color &colour);

	float getRed() const;
	float getGreen() const;
	float getBlue() const;

	void setRed(float red);
	void setGreen(float green);
	void setBlue(float blue);

	static Colour average(std::vector<Colour> colours);

	QColor qtColour() const;
	huestream::Color hueColour() const;

protected:
	virtual float clamp(float value) const;

private:
	float _red = 0, _green = 0, _blue = 0;
};
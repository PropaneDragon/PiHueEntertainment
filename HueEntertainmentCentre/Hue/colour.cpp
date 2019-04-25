#include "colour.h"

Colour::Colour(float r, float g, float b)
{
	_red = r;
	_green = g;
	_blue = b;
}

Colour::Colour(const QColor &colour) : Colour(colour.redF(), colour.greenF(), colour.blueF())
{
}

Colour::Colour(const huestream::Color &colour) : Colour(colour.GetR(), colour.GetG(), colour.GetB())
{
}

float Colour::getRed() const
{
	return _red;
}

float Colour::getGreen() const
{
	return _green;
}

float Colour::getBlue() const
{
	return _blue;
}

void Colour::setRed(float red)
{
	_red = clamp(red);
}

void Colour::setGreen(float green)
{
	_green = clamp(green);
}

void Colour::setBlue(float blue)
{
	_blue = clamp(blue);
}

Colour Colour::average(std::vector<Colour> colours)
{
	auto total = colours.size();
	float totalR = 0, totalG = 0, totalB = 0;

	for (auto colour : colours) {
		totalR += colour.getRed();
		totalG += colour.getGreen();
		totalB += colour.getBlue();
	}

	if (total > 0) {
		totalR /= total;
		totalG /= total;
		totalB /= total;
	}

	return Colour(totalR, totalG, totalB);
}

QColor Colour::qtColour() const
{
	return QColor(_red * 255, _green * 255, _blue * 255);
}

huestream::Color Colour::hueColour() const
{
	return huestream::Color(_red, _green, _blue);
}

float Colour::clamp(float value) const
{
	return value > 1.0 ? 1.0 : (value < 0.0 ? 0.0 : value);
}

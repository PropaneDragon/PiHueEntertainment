#include "colourArea.h"

ColourArea::ColourArea(CameraCapture *capture, std::vector<huestream::Area> areas, const Area &coverage)
{
	_coverage = coverage;
	_areas.clear();

	for (auto area : areas) {
		_areas.push_back(std::make_shared<huestream::Area>(area));
	}

	_colourGroup = std::make_shared<ColourGroup>();
}

bool ColourArea::pointIsInside(int x, int y, CameraCapture *capture) const
{
	auto resolution = capture->lastViewfinderResolution();
	auto xPercentage = ((float)x / resolution.width()) * 100;
	auto yPercentage = ((float)y / resolution.height()) * 100;

	auto xInBounds = xPercentage >= _coverage.getLeftPercentage() && xPercentage <= (_coverage.getLeftPercentage() + _coverage.getWidthPercentage());
	auto yInBounds = yPercentage >= _coverage.getTopPercentage() && yPercentage <= (_coverage.getTopPercentage() + _coverage.getHeightPercentage());

	return xInBounds && yInBounds;
}

bool ColourArea::pointIsInside(QPoint &point, CameraCapture *capture) const
{
	return pointIsInside(point.x(), point.y(), capture);
}

huestream::AreaList ColourArea::getAreas() const
{
	return _areas;
}

std::shared_ptr<ColourGroup> ColourArea::getColourGroup() const
{
	return _colourGroup;
}

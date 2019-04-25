#pragma once

#include <vector>

#include "huestream/common/data/Area.h"
#include "Qt/cameraCapture.h"

#include "area.h"
#include "colourGroup.h"

class ColourArea
{
public:
	ColourArea(CameraCapture *capture, std::vector<huestream::Area> areas, const Area &coverage);

	bool pointIsInside(int x, int y, CameraCapture *capture) const;
	bool pointIsInside(QPoint &point, CameraCapture *capture) const;

	huestream::AreaList getAreas() const;
	std::shared_ptr<ColourGroup> getColourGroup() const;

private:
	Area _coverage;

	std::vector<huestream::AreaPtr> _areas = { std::make_shared<huestream::Area>(huestream::Area::All) };
	std::shared_ptr<ColourGroup> _colourGroup = nullptr;
};
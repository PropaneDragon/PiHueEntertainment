#pragma once

#include "huestream/common/data/Area.h"
#include "../Qt/cameraCapture.h"

#include "area.h"
#include "colourGroup.h"

class ColourArea
{
public:
	ColourArea(std::shared_ptr<CameraCapture> capture, std::vector<huestream::Area> areas, const Area &coverage);

	bool pointIsInside(int x, int y) const;

	huestream::AreaList getAreas() const;
	std::shared_ptr<ColourGroup> getColourGroup() const;

private:
	Area _coverage;
	QSize _expectedSize;

	std::vector<huestream::AreaPtr> _areas = { std::make_shared<huestream::Area>(huestream::Area::All) };
	std::shared_ptr<ColourGroup> _colourGroup = nullptr;
};
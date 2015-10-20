#pragma once
#include "Position.h"
#include "../Cells/Cell.h"
#include <map>
#include "Road.h"


class RoadSystem
{
	std::map<Position, Cell> roadSystem;
	Road firstRoad;


public:

	RoadSystem();

	RoadSystem build();

	RoadSystem WithFirstRoad(Road road);

	RoadSystem WithSecondRoad(Road road);

	RoadSystem WithThirdRoad(Road road);

	RoadSystem WithFourthRoad(Road road);

	Road GetFirstRoad();
};

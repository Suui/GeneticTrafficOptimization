#pragma once
#include "Position.h"
#include "../Cells/Cell.h"
#include <map>
#include "Road.h"


class RoadSystem
{
	std::map<Position, Cell> roadSystem;
	
	Road firstRoad, 
		 secondRoad, 
		 thirdRoad;


public:

	RoadSystem() {}

	RoadSystem& WithFirstRoad(Road road);

	RoadSystem& WithSecondRoad(Road road);

	RoadSystem& WithThirdRoad(Road road);

	RoadSystem& WithFourthRoad(Road road);

	Road GetFirstRoad() { return firstRoad; }

	Road GetSecondRoad() { return secondRoad; }

	Road GetThirdRoad() { return thirdRoad; }
};

#pragma once

#include "Road.h"
#include "Position.h"
#include "../Cells/Cell.h"
#include <map>


class RoadSystem
{
	std::map<Position, Cell> roadSystem;
	
	Road firstRoad, 
		 secondRoad, 
		 thirdRoad,
		 fourthRoad;

	void SetupRoadSystemFor(Road& road);


public:

	RoadSystem() {}

	RoadSystem& WithFirstRoad(Road road);

	RoadSystem& WithSecondRoad(Road road);
	
	RoadSystem& WithThirdRoad(Road road);

	RoadSystem& WithFourthRoad(Road road);

	Road GetFirstRoad() { return firstRoad; }

	Road GetSecondRoad() { return secondRoad; }

	Road GetThirdRoad() { return thirdRoad; }

	Road GetFourthRoad() { return fourthRoad; }
};

#pragma once

#include "Road.h"
#include "Position.h"
#include "../Cells/Cell.h"
#include "TrafficLightPair.h"
#include <map>


class RoadSystem
{

protected:

	std::map<Position, Cell> roadSystem;
	
	Road firstRoad, 
		 secondRoad, 
		 thirdRoad,
		 fourthRoad;

	TrafficLightPair firstTrafficLightPair,
					 secondTrafficLightPair,
					 thirTrafficLightPair,
					 fourTrafficLightPair;

	void SetupRoadSystemFor(Road& fieldRoad, Road& road);

	void SetUpFirstTrafficLightPair();

public:

	RoadSystem() {}

	virtual RoadSystem& WithFirstRoad(Road road);

	virtual RoadSystem& WithSecondRoad(Road road);
	
	virtual RoadSystem& WithThirdRoad(Road road);

	virtual RoadSystem& WithFourthRoad(Road road);

	void SetUpTrafficLightPairs();
};

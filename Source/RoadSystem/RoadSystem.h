#pragma once

#include "Road.h"
#include "Position.h"
#include "../Cells/Cell.h"
#include "TrafficLightPair.h"
#include <map>


class RoadSystem
{

protected:

	std::map<Position, std::shared_ptr<Cell>> roadSystem;
	
	Road firstRoad, 
		 secondRoad, 
		 thirdRoad,
		 fourthRoad;

	TrafficLightPair firstTrafficLightPair,
					 secondTrafficLightPair,
					 thirTrafficLightPair,
					 fourthTrafficLightPair;

	void SetupRoadSystemFor(Road& road);

	void SetUpFirstTrafficLightPair();

	void SetUpSecondTrafficLightPair();

	void SetUpThirdTrafficLightPair();

	void SetUpFourthTrafficLightPair();


public:

	RoadSystem() {}

	virtual RoadSystem& WithFirstRoad(Road road);

	virtual RoadSystem& WithSecondRoad(Road road);
	
	virtual RoadSystem& WithThirdRoad(Road road);

	virtual RoadSystem& WithFourthRoad(Road road);

	void SetUpTrafficLightPairs();

	void SetTrafficLightCycles(std::vector<int> binaryCycle);
	
	void IncludeVehiclesInEntryCells();
};

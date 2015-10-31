#pragma once

#include "Road.h"
#include "Position.h"
#include "../Cells/Cell.h"
#include "TrafficLightPair.h"
#include "../ParetoData/ParetoData.h"
#include <map>


class RoadSystem
{

protected:

	std::map<Position, std::shared_ptr<Cell>> roadSystem;
	ParetoData gasData;
	
	Road firstRoad, 
		 secondRoad, 
		 thirdRoad,
		 fourthRoad;

	TrafficLightPair firstTrafficLightPair,
					 secondTrafficLightPair,
					 thirdTrafficLightPair,
					 fourthTrafficLightPair;

	void SetupRoadSystemFor(Road& road);

	void SetUpFirstTrafficLightPair();

	void SetUpSecondTrafficLightPair();

	void SetUpThirdTrafficLightPair();

	void SetUpFourthTrafficLightPair();

	void AdvanceVehiclesInRoad(Road& road);

	bool VehicleDoesntBelongToRoad(Road& road, std::shared_ptr<Cell>& currentCell);

	void MoveVehicle(Road& road, std::shared_ptr<Cell>& currentCell, std::shared_ptr<Cell>& lastCell);


public:

	RoadSystem() {}

	virtual RoadSystem& WithFirstRoad(Road road);

	virtual RoadSystem& WithSecondRoad(Road road);
	
	virtual RoadSystem& WithThirdRoad(Road road);

	virtual RoadSystem& WithFourthRoad(Road road);

	void SetUpTrafficLightPairs();

	void SetTrafficLightCycles(std::vector<int> binaryCycle);
	
	void PerformStep();

	void AddVehiclesInEntryCells();
	
	void UpdateTrafficLights();

	void ResetExitedVehicles();
	
	int GetExitedVehicles();
};

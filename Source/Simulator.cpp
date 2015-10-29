#include "Simulator.h"
#include "Builders/RoadBuilder.h"
#include "Builders/BinaryCycleBuilder.h"


Simulator::Simulator()
{
	roadSystem = RoadSystem()
				.WithFirstRoad(RoadBuilder::BuildFirstRoad())
				.WithSecondRoad(RoadBuilder::BuildSecondRoad())
				.WithThirdRoad(RoadBuilder::BuildThirdRoad())
				.WithFourthRoad(RoadBuilder::BuildFourthRoad());

	roadSystem.SetUpTrafficLightPairs();
	roadSystem.SetTrafficLightCycles(BinaryCycleBuilder::BuildRandom());
}


void Simulator::Simulate()
{
	for (int i = 0; i < SIMULATION_LENGTH; ++i)
	{
		if (i % 5 == 0) roadSystem.IncludeVehiclesInEntryCells();
		
	}
	
}
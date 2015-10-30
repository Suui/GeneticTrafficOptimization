#include "Simulator.h"
#include "../Builders/RoadBuilder.h"
#include "../Builders/BinaryCycleBuilder.h"


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
	for (int i = 0; i < SIMULATION_STEPS; ++i)
	{
		if (i % 3 == 0) roadSystem.AddVehiclesInEntryCells();
		if (i % 10 == 0) roadSystem.UpdateTrafficLights();
		roadSystem.PerformStep();
	}

	exitedVehiclesForLastSimulation = roadSystem.GetExitedVehicles();
	roadSystem.ResetExitedVehicles();
}

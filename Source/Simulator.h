#pragma once

#include "RoadSystem/RoadSystem.h"


class Simulator
{
	RoadSystem roadSystem;
	int SIMULATION_STEPS = 7200;


public:

	Simulator();

	void Simulate();

	void SetTrafficLightCycles(std::vector<int> binaryCycle) { roadSystem.SetTrafficLightCycles(binaryCycle); }

	void SetSimulationSteps(int simulationSteps) { SIMULATION_STEPS = simulationSteps; }

	int GetExitedVehicles() { return roadSystem.GetExitedVehicles(); }
};

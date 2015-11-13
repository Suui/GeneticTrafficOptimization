#pragma once

#include "../RoadSystem/RoadSystem.h"


class Simulator
{
	RoadSystem roadSystem;
	int SIMULATION_STEPS = 7200;
	int exitedVehiclesForLastSimulation = 0;
	int averageGHGForLastSimulation = 0;


public:

	Simulator();

	void Simulate();

	void SetTrafficLightCycles(std::vector<int> binaryCycle) { roadSystem.SetTrafficLightCycles(binaryCycle); }

	void SetSimulationSteps(int simulationSteps) { SIMULATION_STEPS = simulationSteps; }

	int& GetExitedVehiclesForLastSimulation() { return exitedVehiclesForLastSimulation; }

	int& GetAverageGHGForLastSimulation() { return averageGHGForLastSimulation; }
};

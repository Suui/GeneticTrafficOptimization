#pragma once
#include <vector>
#include "../Simulation/Simulator.h"


class Tournament
{
	Simulator simulator;
	std::vector<std::vector<int>> binaryCyclesPool, selectedBinaryCycles;
	std::vector<int> bestCycle;
	int confrontations, poolSize, bestFitness;

	void SetPool();

	void SetupSimulatorForNextSimulation(int& index);

	void UpdateBestFitnessAndCycle(int randomIndex, int fitness);


public:

	explicit Tournament(int confrontations, int poolSize);

	void Execute();
};

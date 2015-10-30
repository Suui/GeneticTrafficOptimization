#pragma once
#include <vector>
#include "../Simulation/Simulator.h"


class Tournament
{
	Simulator simulator;
	std::vector<std::vector<int>> binaryCyclesPool;
	std::vector<int> bestCycle;
	int confrontations, poolSize, bestFitness;

	void SetPool();

	void CheckFitness(int& randomIndex);

	void SetupSimulatorForNextSimulation(int& randomIndex);

	void UpdateBestFitnessAndCycle(int randomIndex, int fitness);


public:

	explicit Tournament(int confrontations, int poolSize);
	
	void Execute();
};

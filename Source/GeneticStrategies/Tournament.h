#pragma once

#include "../Simulation/Simulator.h"
#include "FitnessBinaryCyclePair.h"
#include <vector>
#include <mutex>


class Tournament
{
	Simulator firSimulator, secondSimulator, thirdSimulator, fourthSimulator;
	std::vector<std::vector<int>> binaryCyclesPool;
	std::vector<FitnessBinaryCyclePair> selectedBinaryCycles;
	int generations, poolSize;

	static std::mutex mutex;

	void SetPool();
	
	void SetupSimulators();
	
	void Compete(Simulator& simulator);

	void SetupSimulatorForNextSimulation(int& index);


public:

	explicit Tournament(int generations, int populationSize);

	void Execute();
};

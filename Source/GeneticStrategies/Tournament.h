#pragma once

#include "../Simulation/Simulator.h"
#include "FitnessBinaryCyclePair.h"
#include <vector>
#include <mutex>


class Tournament
{
	const int NUMBER_OF_THREADS = 4;
	static std::mutex mutex;
	int generations, poolSize;

	Simulator firSimulator, secondSimulator, thirdSimulator, fourthSimulator;
	std::vector<std::vector<int>> binaryCyclesPool;
	std::vector<FitnessBinaryCyclePair> selectedBinaryCycles;

	void SetPool();
	
	void SetupSimulators();
	
	void Compete(Simulator& simulator);

	void SetUpNextGeneration();


public:

	explicit Tournament(int generations, int populationSize);

	void Execute();
};

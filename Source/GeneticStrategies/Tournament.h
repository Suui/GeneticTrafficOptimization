#pragma once

#include "../Simulation/Simulator.h"
#include "Fitness.h"
#include <vector>
#include <mutex>


class Tournament
{
	const int NUMBER_OF_THREADS = 4;
	static std::mutex mutex;
	int generations, poolSize;

	Simulator firSimulator, secondSimulator, thirdSimulator, fourthSimulator;
	std::vector<std::vector<int>> binaryCyclesPool;
	std::vector<Fitness> selectedBinaryCycles;

	void SetPool();
	
	void Compete(Simulator& simulator);
	
	void SortSelectedGenesByFitness();

	void Elitism();

	void TwoPointCrossover();

	void SetUpNextGeneration();

	void RunSimulations();


public:

	explicit Tournament(int generations, int populationSize);

	void Execute();
};

﻿#include "Tournament.h"
#include "TwoPointCrossover.h"
#include "../Builders/BinaryCycleBuilder.h"
#include "../Utility/Math.hpp"
#include "../Utility/Logger.hpp"
#include <thread>
#include <random>
#include <algorithm>


std::mutex Tournament::mutex;

Tournament::Tournament(int generations, int populationSize) : generations(generations),
															  poolSize(populationSize - populationSize % NUMBER_OF_THREADS)
{
	Logger::LogLine("Setting up tournament's pool...");
	SetPool();
	SetupSimulators();
	Logger::LogLine("Tournament's pool setup finished, starting confrontations: ");
}


void Tournament::SetPool()
{
	binaryCyclesPool = std::vector<std::vector<int>>(poolSize);
	
	for (int i = 0; i < poolSize; i++)
		binaryCyclesPool[i] = BinaryCycleBuilder::BuildRandom();
}


void Tournament::SetupSimulators()
{
	firSimulator.SetSimulationSteps(900);
	secondSimulator.SetSimulationSteps(900);
	thirdSimulator.SetSimulationSteps(900);
	fourthSimulator.SetSimulationSteps(900);
}


void Tournament::Compete(Simulator& simulator)
{
	std::random_device randomGenerator;
	std::mt19937 seed(randomGenerator());
	std::uniform_int_distribution<> random(0, poolSize - 1);

	int index = random(seed);
	simulator.SetTrafficLightCycles(binaryCyclesPool[index]);
	simulator.Simulate();
	FitnessBinaryCyclePair firstResult(binaryCyclesPool[index], simulator.GetExitedVehiclesForLastSimulation());

	index = random(seed);
	simulator.SetTrafficLightCycles(binaryCyclesPool[index]);
	simulator.Simulate();
	FitnessBinaryCyclePair secondResult(binaryCyclesPool[index], simulator.GetExitedVehiclesForLastSimulation());

	std::lock_guard<std::mutex> guard(mutex);
	if (firstResult >= secondResult)
		selectedBinaryCycles.push_back(firstResult);
	else
		selectedBinaryCycles.push_back(secondResult);
}


void Tournament::SortSelectedGenesByFitness()
{
	std::sort(selectedBinaryCycles.begin(), selectedBinaryCycles.end(), std::greater<FitnessBinaryCyclePair>());
}


void Tournament::SetUpNextGeneration()
{
	// Elitism
	binaryCyclesPool[0] = selectedBinaryCycles[0].GetBinaryCycle();
	binaryCyclesPool[1] = selectedBinaryCycles[1].GetBinaryCycle();

	// Two Point Crossover
	for (auto i = 2, index = 2; i < poolSize; i += 2, index++)
	{
		std::vector<int> father = selectedBinaryCycles[index].GetBinaryCycle();
		std::vector<int> mother = selectedBinaryCycles[Math::RandomExclusive(poolSize)].GetBinaryCycle();

		std::vector<std::vector<int>> sons = TwoPointCrossover::Reproduce(father, mother);

		binaryCyclesPool[i] = sons[0];
		binaryCyclesPool[i + 1] = sons[1];
	}

	selectedBinaryCycles.clear();
}


void Tournament::PrintLastResults()
{
	Logger::LogLine("Running last simulation with the best fitness...");
	firSimulator.SetSimulationSteps(7200);
	firSimulator.SetTrafficLightCycles(binaryCyclesPool[0]);
	Logger::LogLine("Total vehicles that exited the roads: ");
	Logger::LogLine(firSimulator.GetExitedVehiclesForLastSimulation());
}


void Tournament::Execute()
{
	for (int i = 0; i < generations; i++)
	{
		Logger::LogLine("Selected genes...");

		for (int j = 0; j < poolSize / NUMBER_OF_THREADS; j++)
		{
			std::thread firstSimulation(&Tournament::Compete, this, std::ref(firSimulator));
			std::thread secondSimulation(&Tournament::Compete, this, std::ref(secondSimulator));
			std::thread thirdSimulation(&Tournament::Compete, this, std::ref(thirdSimulator));
			std::thread fourthSimulation(&Tournament::Compete, this, std::ref(fourthSimulator));

			firstSimulation.join();
			secondSimulation.join();
			thirdSimulation.join();
			fourthSimulation.join();
			
			Logger::LogLine(selectedBinaryCycles.size());
		}

		SortSelectedGenesByFitness();
		Logger::LogLine("\nBest Fitness in this generation: ");
		Logger::LogLine(selectedBinaryCycles[0].GetFitness());

		SetUpNextGeneration();
	}

	PrintLastResults();
}

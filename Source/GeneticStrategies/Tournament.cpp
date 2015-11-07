#include "Tournament.h"
#include "../Builders/BinaryCycleBuilder.h"
#include "../Utility/Logger.hpp"
#include <thread>
#include <random>
#include <algorithm>


std::mutex Tournament::mutex;

Tournament::Tournament(int generations, int populationSize) : generations(generations), poolSize(populationSize)
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
	{
		selectedBinaryCycles.push_back(firstResult);
		Logger::LogLine(firstResult.GetFitness());
	}
	else
	{
		selectedBinaryCycles.push_back(secondResult);
		Logger::LogLine(secondResult.GetFitness());
	}
}


void Tournament::SetUpNextGeneration()
{
	std::sort(selectedBinaryCycles.begin(), selectedBinaryCycles.end(), std::greater<FitnessBinaryCyclePair>());
	
}


void Tournament::Execute()
{
	for (int i = 0; i < generations; i++)
	{
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

		SetUpNextGeneration();
	}
}

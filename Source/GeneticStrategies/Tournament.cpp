#include "Tournament.h"
#include "../Builders/BinaryCycleBuilder.h"
#include "../Utility/Math.hpp"
#include "../Utility/Logger.hpp"


Tournament::Tournament(int confrontations, int poolSize) : confrontations(confrontations), poolSize(poolSize)
{
	Logger::LogLine("Setting up tournament's pool...");
	SetPool();
	Logger::LogLine("Tournament's pool setup finished, starting confrontations: ");
}


void Tournament::SetPool()
{
	binaryCyclesPool = std::vector<std::vector<int>>(poolSize);
	
	for (int i = 0; i < poolSize; i++)
		binaryCyclesPool[i] = BinaryCycleBuilder::BuildRandom();
}


void Tournament::Execute()
{
	for (int i = 0; i < confrontations; i++)
	{
		int firstIndex, secondIndex;
		SetupSimulatorForNextSimulation(firstIndex);
		simulator.Simulate();
		int firstFitness = simulator.GetExitedVehiclesForLastSimulation();

		SetupSimulatorForNextSimulation(secondIndex);
		simulator.Simulate();
		int secondFitness = simulator.GetExitedVehiclesForLastSimulation();

		if (firstFitness >= secondFitness)
		{
			selectedBinaryCycles.push_back(binaryCyclesPool[firstIndex]);		
			Logger::LogLine(firstFitness);
		}
		else
		{
			selectedBinaryCycles.push_back(binaryCyclesPool[secondIndex]);
			Logger::LogLine(secondFitness);
		}
	}
}


void Tournament::SetupSimulatorForNextSimulation(int& index)
{
	index = Math::RandomExclusive(binaryCyclesPool.size());
	simulator.SetTrafficLightCycles(binaryCyclesPool[index]);
}


void Tournament::UpdateBestFitnessAndCycle(int randomIndex, int fitness)
{
	bestCycle = binaryCyclesPool[randomIndex];
	bestFitness = fitness;
}

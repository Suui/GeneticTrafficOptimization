#include "Tournament.h"
#include "../Builders/BinaryCycleBuilder.h"
#include "../Utility/Math.hpp"
#include "../Utility/Logger.hpp"


Tournament::Tournament(int confrontations, int poolSize) : confrontations(confrontations), poolSize(poolSize)
{
	Logger::LogLine("Setting up tournament's pool...");
	SetPool();
	Logger::LogLine("Tournament's pool setup finished, starting confrontations:");
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
		int randomIndex;
		SetupSimulatorForNextSimulation(randomIndex);
		simulator.Simulate();

		CheckFitness(randomIndex);

		binaryCyclesPool.erase(binaryCyclesPool.begin() + randomIndex);
		Logger::LogLine(bestFitness);
	}
}


void Tournament::SetupSimulatorForNextSimulation(int& randomIndex)
{
	Math::SetRandomSeed();
	randomIndex = Math::RandomExclusive(binaryCyclesPool.size());
	simulator.SetTrafficLightCycles(binaryCyclesPool[randomIndex]);
}


void Tournament::CheckFitness(int& randomIndex)
{
	int fitness = simulator.GetExitedVehiclesForLastSimulation();

	if (fitness > bestFitness)
		UpdateBestFitnessAndCycle(randomIndex, fitness);
}


void Tournament::UpdateBestFitnessAndCycle(int randomIndex, int fitness)
{
	bestCycle = binaryCyclesPool[randomIndex];
	bestFitness = fitness;
}

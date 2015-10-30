#include "Simulator.h"
#include <iostream>
#include "Builders/BinaryCycleBuilder.h"
#include <ctime>


void SetRandomSeed()
{
	srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
}


int main()
{
	int tournamentPoolSize = 10;

	Simulator simulator;
	std::vector<int> bestCycle;
	std::vector<std::vector<int>> possibleBinaryCycles(tournamentPoolSize);

	for (int i = 0; i < tournamentPoolSize; i++)
		possibleBinaryCycles[i] = BinaryCycleBuilder::BuildRandom();

	int bestFitness = 0, fitness;
	for (int i = 0; i < tournamentPoolSize; i++)
	{
		SetRandomSeed();
		int randomIndex = rand() % possibleBinaryCycles.size();
		simulator.SetTrafficLightCycles(possibleBinaryCycles[randomIndex]);

		simulator.Simulate();
		fitness = simulator.GetExitedVehiclesForLastSimulation();
		if (fitness > bestFitness)
		{
			bestCycle = possibleBinaryCycles[randomIndex];
			bestFitness = fitness;
		}

		possibleBinaryCycles.erase(possibleBinaryCycles.begin() + randomIndex);
		std::cout << bestFitness << std::endl;
	}

	for (unsigned int i = 0; i < bestCycle.size(); i++)
		std::cout << bestCycle[i] << ", ";

	return 0;
}
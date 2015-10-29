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
	Simulator simulator;
	std::vector<int> bestCycle;
	std::vector<std::vector<int>> possibleBinaryCycles(100);

	for (int i = 0; i < 100; i++)
		possibleBinaryCycles[i] = BinaryCycleBuilder::BuildRandom();

	int bestFitness = 0, fitness;
	for (int i = 0; i < 100; i++)
	{
		SetRandomSeed();
		int randomIndex = rand() % possibleBinaryCycles.size();
		simulator.SetTrafficLightCycles(possibleBinaryCycles[randomIndex]);
		simulator.Simulate();
		fitness = simulator.GetExitedVehicles();
		if (fitness > bestFitness)
		{
			bestCycle = possibleBinaryCycles[randomIndex];
			bestFitness = fitness;
		}
		std::cout << simulator.GetExitedVehicles() << std::endl;
		simulator.ResetExitedVehicles();
		possibleBinaryCycles.erase(possibleBinaryCycles.begin() + randomIndex);
	}

	for (int i = 0; i < bestCycle.size(); i++)
		std::cout << bestCycle[i] << ", ";

	return 0;
}
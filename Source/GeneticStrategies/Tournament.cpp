#include "Tournament.h"
#include "TwoPointCrossover.h"
#include "../Builders/BinaryCycleBuilder.h"
#include "../Utility/Math.hpp"
#include "../Utility/Logger.hpp"
#include <thread>
#include <random>
#include <algorithm>
#include "Mutation.h"


std::mutex Tournament::mutex;

Tournament::Tournament(int generations, int populationSize) : generations(generations),
															  poolSize(populationSize - populationSize % NUMBER_OF_THREADS)
{
	SetPool();
}


void Tournament::SetPool()
{
	binaryCyclesPool = std::vector<std::vector<int>>(poolSize);
	
	for (int i = 0; i < poolSize; i++)
		binaryCyclesPool[i] = BinaryCycleBuilder::BuildRandom();
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


void Tournament::Elitism()
{
	binaryCyclesPool[0] = selectedBinaryCycles[0].GetBinaryCycle();
	binaryCyclesPool[1] = selectedBinaryCycles[1].GetBinaryCycle();
}


	// Two Point Crossover
	for (auto i = 2, index = 0; i < poolSize; i += 2)
	{
		std::vector<int> father = selectedBinaryCycles[index++].GetBinaryCycle();
		std::vector<int> mother = selectedBinaryCycles[Math::RandomExclusive(poolSize)].GetBinaryCycle();

		std::vector<std::vector<int>> sons = TwoPointCrossover::Reproduce(father, mother);

		Mutation::MaybeMutate(sons[0]);
		Mutation::MaybeMutate(sons[1]);

		binaryCyclesPool[i] = sons[0];
		binaryCyclesPool[i + 1] = sons[1];
	}

void Tournament::SetUpNextGeneration()
{
	Elitism();

	selectedBinaryCycles.clear();
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
		}

		SortSelectedGenesByFitness();
		std::cout << "\nBest fitness in generation " << i + 1 << ": " << std::endl;
		Logger::LogLine(selectedBinaryCycles[0].GetFitness());

		SetUpNextGeneration();
	}
}

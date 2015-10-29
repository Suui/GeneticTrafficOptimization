#include "BinaryCycleBuilder.h"
#include <ctime>


std::vector<int> BinaryCycleBuilder::Build()
{
	return std::vector<int> { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}


std::vector<int> BinaryCycleBuilder::BuildRandom()
{
	std::vector<int> binaryCycle;

	for (int i = 0; i < 48; i++)
	{
		SetRandomSeed();
		binaryCycle.push_back(rand() % 2);
	}

	return binaryCycle;
}


void BinaryCycleBuilder::SetRandomSeed()
{
	srand(static_cast<unsigned int>(rand() ^ time(nullptr)));
}
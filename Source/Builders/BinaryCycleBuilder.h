#pragma once

#include <vector>


class BinaryCycleBuilder
{
	static void SetRandomSeed();


public:

	static std::vector<int> BuildWithoutChange();

	static std::vector<int> BuildRandom();
};

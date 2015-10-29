#pragma once

#include <vector>


class BinaryCycleBuilder
{
	static void SetRandomSeed();


public:

	static std::vector<int> Build();

	static std::vector<int> BuildRandom();
};

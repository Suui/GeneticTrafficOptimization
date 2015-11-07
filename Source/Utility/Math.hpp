#pragma once

#include <ctime>
#include <random>


class Math
{

public:

	static void SetRandomSeed() { srand(static_cast<unsigned int>(rand() ^ time(nullptr))); }

	static int RandomExclusive(int maxExclusive)
	{
		SetRandomSeed();
		return rand() % maxExclusive;
	}
};

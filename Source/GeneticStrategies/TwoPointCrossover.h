#pragma once

#include <vector>


class TwoPointCrossover
{
	static std::vector<int> Crossover(std::vector<int>& firstParent, std::vector<int>& secondParent, int& firstPoint, int& secondPoint);

public:

	static std::vector<std::vector<int>> Reproduce(std::vector<int>& father, std::vector<int>& mother);
};

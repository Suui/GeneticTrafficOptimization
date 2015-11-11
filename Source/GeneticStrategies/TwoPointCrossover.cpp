#include "TwoPointCrossover.h"
#include "../Utility/Math.hpp"


std::vector<int> TwoPointCrossover::Crossover(std::vector<int>& firstParent, std::vector<int>& secondParent, int& firstPoint, int& secondPoint)
{
	std::vector<int> son(firstParent.begin(), firstParent.begin() + firstPoint);

	son.insert(son.end(), secondParent.begin() + firstPoint, secondParent.begin() + secondPoint);
	son.insert(son.end(), firstParent.begin() + secondPoint, firstParent.end());

	return son;
}


std::vector<std::vector<int>> TwoPointCrossover::Reproduce(std::vector<int>& father, std::vector<int>& mother)
{
	int firstPoint = Math::RandomExclusive(father.size());
	int secondPoint = firstPoint + Math::RandomExclusive(father.size() - firstPoint);

	std::vector<std::vector<int>> result(2);

	result[0] = Crossover(father, mother, firstPoint, secondPoint);
	result[1] = Crossover(mother, father, firstPoint, secondPoint);

	return result;
}
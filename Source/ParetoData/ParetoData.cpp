#include "ParetoData.h"


int ParetoData::GetGHGAverage()
{
	std::vector<int> totals;

	for (auto it : gasData)
	{
		auto sum = 0, previousValue = 1;
		for (auto value : it.second)
		{
			if (previousValue == 0 && value == 1) sum += 1;
			previousValue = value;
		}
		totals.push_back(sum);
	}

	auto average = 0;
	for (auto value : totals)
	{
		average += value;
	}

	return average / totals.size();
}

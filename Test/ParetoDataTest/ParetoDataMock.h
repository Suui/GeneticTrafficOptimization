#pragma once

#include <ParetoData/ParetoData.h>


struct ParetoDataMock : ParetoData
{
	void SetGasData(std::map<int, std::vector<int>>& data)
	{
		gasData = data;
	}
};

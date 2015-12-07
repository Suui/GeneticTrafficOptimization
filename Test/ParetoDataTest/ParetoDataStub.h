#pragma once

#include <ParetoData/ParetoData.h>


struct ParetoDataStub : ParetoData
{
	void StubSetGasData(std::map<int, std::vector<int>>& data)
	{
		gasData = data;
	}
};

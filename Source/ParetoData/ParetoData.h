﻿#pragma once

#include "Vehicle.hpp"
#include <vector>
#include <memory>
#include <map>


struct ParetoData
{
	void AddDataFrom(std::shared_ptr<Vehicle>& vehicle) { gasData[gasData.size()] = vehicle->GetGasData(); }

	double GetGHGAverage();

	void Reset() { gasData.clear(); }


protected:

	std::map<int, std::vector<int>> gasData;
};

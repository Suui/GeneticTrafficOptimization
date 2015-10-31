#pragma once

#include <vector>


class Vehicle
{
	std::vector<int> gasData;


public:


	Vehicle() {}

	void AddMovement(int movement) { gasData.push_back(movement); }

	void SetlastMovement(int movement) { gasData[gasData.size() - 1] = movement; }

	std::vector<int> GetGasData() { return gasData; }
};

#pragma once

#include <vector>


class Vehicle
{
	std::vector<int> gasData;
	const int id;


public:

	explicit Vehicle(int id) : id(id){}

	void AddMovement(int movement) { gasData.push_back(movement); }

	void SetlastMovement(int movement) { gasData[gasData.size() - 1] = movement; }

	int GetID() { return id; }

	std::vector<int> GetGasData() { return gasData; }
};

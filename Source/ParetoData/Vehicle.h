#pragma once

#include <vector>


class Vehicle
{
	std::vector<int> gasData;
	const int id;

public:

	explicit Vehicle(int id) : id(id){}

	void AddMovement(int movement) { gasData.push_back(movement); }
};

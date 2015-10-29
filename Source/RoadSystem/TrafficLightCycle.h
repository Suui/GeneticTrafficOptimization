#pragma once

#include <vector>


class TrafficLightCycle
{
	std::vector<int> binaryCycle;


public:

	TrafficLightCycle() {}

	explicit TrafficLightCycle(const std::vector<int>& binaryCycle);
};

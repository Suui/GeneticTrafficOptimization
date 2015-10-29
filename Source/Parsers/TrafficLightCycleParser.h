#pragma once
#include <vector>


class TrafficLightCycleParser
{
	std::vector<int> first, second, third, fourth;


public:

	TrafficLightCycleParser(std::vector<int>& binaryCycle);

	const std::vector<int>& GetFirst() const { return first; }

	const std::vector<int>& GetSecond() const { return second; }

	const std::vector<int>& GetThird() const { return third; }

	const std::vector<int>& GetFourth() const { return fourth; }
};

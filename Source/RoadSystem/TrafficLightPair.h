#pragma once

#include "../Cells/Cell.h"
#include <memory>
#include <vector>


class TrafficLightPair
{
	std::shared_ptr<Cell> first;
	std::shared_ptr<Cell> second;
	std::vector<int> binaryCycle;


public:

	TrafficLightPair() {};

	TrafficLightPair(const std::shared_ptr<Cell>& first, const std::shared_ptr<Cell>& second) : first(first), second(second) {}

	void SetBinaryCycle(const std::vector<int>& binaryCycle) { this->binaryCycle = binaryCycle; }
};

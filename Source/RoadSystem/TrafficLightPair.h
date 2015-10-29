#pragma once

#include "../Cells/Cell.h"
#include "TrafficLightCycle.h"
#include <memory>


class TrafficLightPair
{
	std::shared_ptr<Cell> first;
	std::shared_ptr<Cell> second;
	TrafficLightCycle cycle;


public:

	TrafficLightPair() {};

	TrafficLightPair(const std::shared_ptr<Cell>& first, const std::shared_ptr<Cell>& second) : first(first), second(second) {}
};

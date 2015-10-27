#pragma once
#include "../Cells/TrafficLightCell.h"
#include <memory>


class TrafficLightPair
{
	std::shared_ptr<TrafficLightCell> first;
	std::shared_ptr<TrafficLightCell> second;


public:

	TrafficLightPair() {};

	TrafficLightPair(const std::shared_ptr<TrafficLightCell>& first, const std::shared_ptr<TrafficLightCell>& second) : first(first), second(second) {}
};

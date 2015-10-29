#pragma once

#include "../Cells/Cell.h"
#include <memory>
#include <vector>


class TrafficLightPair
{
	std::shared_ptr<Cell> first;
	std::shared_ptr<Cell> second;
	std::vector<int> binaryCycle;
	int cycleIndex = 0;

	void SwitchTrafficLightStates();


public:

	TrafficLightPair() {};

	TrafficLightPair(const std::shared_ptr<Cell>& first, const std::shared_ptr<Cell>& second) : first(first), second(second)
	{
		first->SetTrafficLightState(Green);
		second->SetTrafficLightState(Red);
	}

	void SetBinaryCycle(const std::vector<int>& binaryCycle) { this->binaryCycle = binaryCycle; }

	void UpdateState();
};

#pragma once

#include "Cell.h"


struct TrafficLightCell : Cell
{
	TrafficLightCell() { Cell(); trafficLightState = Red; }

	bool isTrafficLight() override { return true; }
};

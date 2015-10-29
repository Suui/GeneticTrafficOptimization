#pragma once

#include "Cell.h"


class TrafficLightCell : public Cell
{

public:

	TrafficLightCell(Direction direction) : Cell(direction) {}

	bool isTrafficLight() override { return true; }
};

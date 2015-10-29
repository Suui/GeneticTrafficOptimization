#pragma once

#include "Cell.h"


class TrafficLightCell : public Cell
{

public:

	bool isTrafficLight() override { return true; }
};

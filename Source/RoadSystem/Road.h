#pragma once
#include "Position.h"
#include "../Cells/Cell.h"
#include <unordered_map>


class TrafficLight;

class Road
{
	std::unordered_map<Position, Cell> road;

public:

	Road();

	Road build();

	Road From(int x, int y);
	
	Road To(int x, int y);

	Road WithFirstTrafficLightIn(int x, int y);

	Road WithSecondTrafficLight(int x, int y);
	
	int Length();

	TrafficLight GetFirstTrafficLight();
};

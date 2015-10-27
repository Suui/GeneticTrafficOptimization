#pragma once

#include "Position.h"
#include <vector>


class Road
{
	std::vector<Position> road;
	
	Position firtTrafficLightPosition, 
			 secondTrafficLightPosition,
			 entryCellPosition,
			 exitCellPosition;

public:

	Road() {}

	~Road() {}

	Road& From(int x, int y);
	
	Road& To(int x, int y);

	Road& WithFirstTrafficLightIn(int x, int y);

	Road& WithSecondTrafficLight(int x, int y);
	
	int Length() const { return road.size(); }

	Position GetFirstTrafficLightPosition() { return firtTrafficLightPosition; }

	Position GetSecondTrafficLightPosition() { return secondTrafficLightPosition; }
	
	Position GetEntryCellPosition() { return entryCellPosition; }
	
	Position GetExitCellPosition() { return exitCellPosition; }
};

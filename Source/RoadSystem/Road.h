#pragma once

#include "Position.h"
#include <vector>


class Road
{
	std::vector<Position> positions;
	
	Position firtTrafficLightPosition, 
			 secondTrafficLightPosition,
			 entryCellPosition,
			 exitCellPosition;


public:

	Road& From(int x, int y);
	
	Road& To(int x, int y);

	Road& WithFirstTrafficLightIn(int x, int y);

	Road& WithSecondTrafficLight(int x, int y);
	
	const std::vector<Position>& GetPositions() { return positions; }

	Position GetFirstTrafficLightPosition() { return firtTrafficLightPosition; }

	Position GetSecondTrafficLightPosition() { return secondTrafficLightPosition; }
	
	Position GetEntryCellPosition() { return entryCellPosition; }
	
	Position GetExitCellPosition() { return exitCellPosition; }

	int Length() const { return positions.size(); }
};

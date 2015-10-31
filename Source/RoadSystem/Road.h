#pragma once

#include "../Utility/Position.h"
#include "../Cells/Cell.h"
#include <vector>


class Road
{
	std::vector<Position> positions;
	
	Position firtTrafficLightPosition, 
			 secondTrafficLightPosition,
			 entryCellPosition,
			 exitCellPosition;

	Direction direction;


public:

	Road& From(int x, int y);
	
	Road& To(int x, int y);

	Road& WithFirstTrafficLightIn(int x, int y);

	Road& WithSecondTrafficLight(int x, int y);

	Road& WithDirection(Direction direction);
	
	const std::vector<Position>& GetPositions() { return positions; }

	Position GetFirstTrafficLightPosition() { return firtTrafficLightPosition; }

	Position GetSecondTrafficLightPosition() { return secondTrafficLightPosition; }
	
	Position GetEntryCellPosition() { return entryCellPosition; }
	
	Position GetExitCellPosition() { return exitCellPosition; }

	Direction GetDirection() { return direction; }

	int Length() const { return positions.size(); }
};

#pragma once

#include "Position.h"
#include "../Cells/Cell.h"
#include <map>
#include <memory>


class Road
{
	std::map<Position, std::shared_ptr<Cell>> road;
	
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
	
	std::shared_ptr<Cell> operator[](Position pos) { return road[pos]; }

	std::map<Position, std::shared_ptr<Cell>>::iterator Begin() { return road.begin(); }
	
	std::map<Position, std::shared_ptr<Cell>>::iterator End() { return road.end(); }
};

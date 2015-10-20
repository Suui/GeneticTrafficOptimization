#pragma once
#include "Position.h"
#include "../Cells/Cell.h"
#include <map>
#include <memory>


class Road
{
	std::map<Position, std::unique_ptr<Cell>> road;
	
	Position firtTrafficLightPosition, 
			 secondTrafficLightPosition,
			 entryCellPosition,
			 exitCellPosition;

public:

	Road();

	Road build();

	Road From(int x, int y);
	
	Road To(int x, int y);

	Road WithFirstTrafficLightIn(int x, int y);

	Road WithSecondTrafficLight(int x, int y);
	
	int Length();

	Position GetFirstTrafficLightPosition();

	Position GetSecondTrafficLightPosition();
	
	Position GetEntryCellPosition();
	
	Position GetExitCellPosition();
	
	std::unique_ptr<Cell> operator[](Position pos) { return std::move(road[pos]); }

	std::map<Position, std::unique_ptr<Cell>>::iterator Begin();
	
	std::map<Position, std::unique_ptr<Cell>>::iterator End();
};

#include "Road.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"
#include "../Cells/TrafficLightCell.h"
#include <memory>


Road& Road::From(int x, int y)
{
	entryCellPosition = Position(x, y);
	road[entryCellPosition] = std::make_shared<EntryCell>();

	return *this;
}


Road& Road::To(int x, int y)
{
	for (int i = entryCellPosition.GetX(); i <= x; i++)
	{
		for (int j = entryCellPosition.GetY(); j <= y; j++)
			road[Position(i, j)] = std::make_shared<Cell>();
	}

	exitCellPosition = Position(x, y);
	road[exitCellPosition] = std::make_shared<ExitCell>();

	return *this;
}


Road& Road::WithFirstTrafficLightIn(int x, int y)
{
	firtTrafficLightPosition = Position(x, y);
	road[firtTrafficLightPosition] = std::make_shared<TrafficLightCell>();
	
	return *this;
}


Road& Road::WithSecondTrafficLight(int x, int y)
{
	secondTrafficLightPosition = Position(x, y);
	road[secondTrafficLightPosition] = std::make_shared<TrafficLightCell>();

	return *this;
}

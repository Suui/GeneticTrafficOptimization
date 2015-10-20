#include "Road.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"
#include "../Cells/TrafficLightCell.h"
#include <memory>


Road::Road()
{

}


Road Road::build()
{
	return *this;
}


Road Road::From(int x, int y)
{
	entryCellPosition = Position(x, y);
	road[entryCellPosition] = std::make_unique<EntryCell>();

	return *this;
}


Road Road::To(int x, int y)
{
	for (int i = entryCellPosition.GetX(); i <= x; i++)
	{
		for (int j = entryCellPosition.GetY(); j <= y; j++)
			road[Position(i, j)] = std::make_unique<Cell>();
	}

	exitCellPosition = Position(x, y);
	road[exitCellPosition] = std::make_unique<ExitCell>();

	return *this;
}


Road Road::WithFirstTrafficLightIn(int x, int y)
{
	firtTrafficLightPosition = Position(x, y);
	road[firtTrafficLightPosition] = std::make_unique<TrafficLightCell>();
	
	return *this;
}


Road Road::WithSecondTrafficLight(int x, int y)
{
	secondTrafficLightPosition = Position(x, y);
	road[secondTrafficLightPosition] = std::make_unique<TrafficLightCell>();

	return *this;
}


int Road::Length()
{
	return road.size();
}


Position Road::GetFirstTrafficLightPosition()
{
	return firtTrafficLightPosition;
}

Position Road::GetSecondTrafficLightPosition()
{
	return secondTrafficLightPosition;
}


Position Road::GetEntryCellPosition()
{
	return entryCellPosition;
}


Position Road::GetExitCellPosition()
{
	return exitCellPosition;
}


std::map<Position, std::unique_ptr<Cell>>::iterator Road::Begin()
{
	return road.begin();
}


std::map<Position, std::unique_ptr<Cell>>::iterator Road::End()
{
	return road.end();
}

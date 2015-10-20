#include "Road.h"
#include "../Exceptions/NotImplementedException.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"
#include "../Cells/TrafficLightCell.h"


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
	road[entryCellPosition] = EntryCell();

	return *this;
}


Road Road::To(int x, int y)
{
	for (int i = entryCellPosition.GetX(); i <= x; i++)
	{
		for (int j = entryCellPosition.GetY(); j <= y; j++)
			road[Position(i, j)] = Cell();
	}

	exitCellPosition = Position(x, y);
	road[exitCellPosition] = ExitCell();

	return *this;
}


Road Road::WithFirstTrafficLightIn(int x, int y)
{
	firtTrafficLightPosition = Position(x, y);
	road[firtTrafficLightPosition] = TrafficLightCell();
	
	return *this;
}


Road Road::WithSecondTrafficLight(int x, int y)
{
	secondTrafficLightPosition = Position(x, y);
	road[secondTrafficLightPosition] = TrafficLightCell();

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

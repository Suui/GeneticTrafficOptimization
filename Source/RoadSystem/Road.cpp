#include "Road.h"


Road& Road::From(int x, int y)
{
	entryCellPosition = Position(x, y);

	return *this;
}


Road& Road::To(int x, int y)
{
	for (int i = entryCellPosition.GetX(); i <= x; i++)
	{
		for (int j = entryCellPosition.GetY(); j <= y; j++)
			road.push_back(Position(i, j));
	}
	exitCellPosition = Position(x, y);

	return *this;
}


Road& Road::WithFirstTrafficLightIn(int x, int y)
{
	firtTrafficLightPosition = Position(x, y);
	
	return *this;
}


Road& Road::WithSecondTrafficLight(int x, int y)
{
	secondTrafficLightPosition = Position(x, y);

	return *this;
}

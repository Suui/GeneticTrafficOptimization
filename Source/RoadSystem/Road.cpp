#include "Road.h"
#include "TrafficLight.h"
#include "../Exceptions/NotImplementedException.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"


Road::Road()
{

}


Road Road::build()
{
	return *this;
}


Road Road::From(int x, int y)
{
	road[Position(x, y)] = EntryCell();
	return *this;
}


Road Road::To(int x, int y)
{
	Position firstPos = road.begin()->first;

	for (int i = firstPos.GetX(); i <= x; i++)
	{
		for (int j = firstPos.GetY(); j <= y; j++)
			road[Position(i, j)] = Cell();
	}

	road[Position(x, y)] = ExitCell();
	return *this;
}


Road Road::WithFirstTrafficLightIn(int x, int y)
{
	throw NotImplementedException();
}


Road Road::WithSecondTrafficLight(int x, int y)
{
	throw NotImplementedException();
}


int Road::Length()
{
	return road.size();
}


TrafficLight Road::GetFirstTrafficLight()
{
	throw NotImplementedException();
}
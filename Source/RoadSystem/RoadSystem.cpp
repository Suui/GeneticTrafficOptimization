#include "RoadSystem.h"
#include "Road.h"
#include "../Exceptions/NotImplementedException.h"


RoadSystem& RoadSystem::WithFirstRoad(Road& road)
{
	firstRoad = road;
	for (auto it = road.Begin(); it != road.End(); ++it)
	{
		roadSystem.insert(std::make_pair(it->first, *it->second));
		firstRoad[it->first] = std::make_shared<Cell>(roadSystem[it->first]);
	}

	return *this;
}


RoadSystem& RoadSystem::WithSecondRoad(Road& road)
{
	throw NotImplementedException();
}


RoadSystem& RoadSystem::WithThirdRoad(Road& road)
{
	throw NotImplementedException();
}


RoadSystem& RoadSystem::WithFourthRoad(Road& road)
{
	throw NotImplementedException();
}

#include "RoadSystem.h"
#include "Road.h"
#include "../Exceptions/NotImplementedException.h"


RoadSystem& RoadSystem::WithFirstRoad(Road road)
{
	firstRoad = road;
	SetupRoadSystemFor(firstRoad);

	return *this;
}


RoadSystem& RoadSystem::WithSecondRoad(Road road)
{
	secondRoad = road;
	SetupRoadSystemFor(secondRoad);

	return *this;
}


void RoadSystem::SetupRoadSystemFor(Road& road)
{
	for (auto it = road.Begin(); it != road.End(); ++it)
	{
		roadSystem.insert(std::make_pair(it->first, *it->second));
		road[it->first].reset();
	}
}


RoadSystem& RoadSystem::WithThirdRoad(Road road)
{
	thirdRoad = road;
	SetupRoadSystemFor(thirdRoad);

	return *this;
}


RoadSystem& RoadSystem::WithFourthRoad(Road road)
{
	throw NotImplementedException();
}

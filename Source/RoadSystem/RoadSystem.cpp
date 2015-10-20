#include "RoadSystem.h"
#include "Road.h"
#include "../Exceptions/NotImplementedException.h"


RoadSystem::RoadSystem()
{
		
}


RoadSystem RoadSystem::build()
{
	return *this;
}


RoadSystem RoadSystem::WithFirstRoad(Road road)
{
	firstRoad = road;
	for (auto it = firstRoad.Begin(); it != firstRoad.End(); ++it)
	{
		//roadSystem[it->first] = *it->second.get();
		//firstRoad[it->first].release();
		//firstRoad[it->first] = std::unique_ptr<Cell>(&roadSystem[it->first]);
	}

	for (auto it = roadSystem.begin(); it != roadSystem.end(); ++it)
	{
		
	}

	return *this;
}


RoadSystem RoadSystem::WithSecondRoad(Road road)
{
	throw NotImplementedException();
}


RoadSystem RoadSystem::WithThirdRoad(Road road)
{
	throw NotImplementedException();
}


RoadSystem RoadSystem::WithFourthRoad(Road road)
{
	throw NotImplementedException();
}


Road RoadSystem::GetFirstRoad()
{
	return firstRoad;
}
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
	throw NotImplementedException();
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
	throw NotImplementedException();
}
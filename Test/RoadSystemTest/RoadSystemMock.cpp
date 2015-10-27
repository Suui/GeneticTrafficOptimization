#include "RoadSystemMock.h"


RoadSystemMock& RoadSystemMock::WithFirstRoad(Road road)
{
	RoadSystem::WithFirstRoad(road);

	return *this;
}


RoadSystemMock& RoadSystemMock::WithSecondRoad(Road road)
{
	RoadSystem::WithSecondRoad(road);

	return *this;
}


RoadSystemMock& RoadSystemMock::WithThirdRoad(Road road)
{
	RoadSystem::WithThirdRoad(road);

	return *this;
}


RoadSystemMock& RoadSystemMock::WithFourthRoad(Road road)
{
	RoadSystem::WithFourthRoad(road);

	return *this;
}

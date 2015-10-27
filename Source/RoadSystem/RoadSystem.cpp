#include "RoadSystem.h"
#include "Road.h"


RoadSystem& RoadSystem::WithFirstRoad(Road road)
{
	firstRoad = road;
	SetupRoadSystemFor(firstRoad, road);

	return *this;
}


RoadSystem& RoadSystem::WithSecondRoad(Road road)
{
	secondRoad = road;
	SetupRoadSystemFor(secondRoad, road);

	return *this;
}


RoadSystem& RoadSystem::WithThirdRoad(Road road)
{
	thirdRoad = road;
	SetupRoadSystemFor(thirdRoad, road);

	return *this;
}


RoadSystem& RoadSystem::WithFourthRoad(Road road)
{
	fourthRoad = road;
	SetupRoadSystemFor(fourthRoad, road);

	return *this;
}


void RoadSystem::SetupRoadSystemFor(Road& fieldRoad, Road& road)
{
	for (auto it = road.Begin(); it != road.End(); ++it)
	{
		if (roadSystem.find(it->first) == roadSystem.end())
		{
			roadSystem.insert(std::make_pair(it->first, *it->second));
			fieldRoad[it->first] = std::make_shared<Cell>(roadSystem[it->first]);
		}
		else
		{
			if (it->first == Position(4, 4)) fieldRoad[it->first] = firstRoad[it->first];
			if (it->first == Position(4, 9)) fieldRoad[it->first] = secondRoad[it->first];
			if (it->first == Position(9, 4)) fieldRoad[it->first] = firstRoad[it->first];
			if (it->first == Position(9, 9)) fieldRoad[it->first] = secondRoad[it->first];
		}
	}
}


void RoadSystem::SetUpTrafficLightPairs()
{
	SetUpFirstTrafficLightPair();
}


void RoadSystem::SetUpFirstTrafficLightPair()
{
	std::shared_ptr<TrafficLightCell> first = std::dynamic_pointer_cast<TrafficLightCell>(firstRoad[firstRoad.GetFirstTrafficLightPosition()]);
	std::shared_ptr<TrafficLightCell> second = std::dynamic_pointer_cast<TrafficLightCell>(thirdRoad[thirdRoad.GetFirstTrafficLightPosition()]);

	if (first && second)
		firstTrafficLightPair = TrafficLightPair(first, second);
}

#include "RoadSystem.h"
#include "Road.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"
#include "../Cells/TrafficLightCell.h"


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


RoadSystem& RoadSystem::WithThirdRoad(Road road)
{
	thirdRoad = road;
	SetupRoadSystemFor(thirdRoad);

	return *this;
}


RoadSystem& RoadSystem::WithFourthRoad(Road road)
{
	fourthRoad = road;
	SetupRoadSystemFor(fourthRoad);

	return *this;
}


void RoadSystem::SetupRoadSystemFor(Road& road)
{
	for (Position pos : road.GetPositions())
		roadSystem[pos] = std::make_shared<Cell>();

	roadSystem[road.GetEntryCellPosition()] = std::make_shared<EntryCell>();
	roadSystem[road.GetExitCellPosition()] = std::make_shared<ExitCell>();
	roadSystem[road.GetFirstTrafficLightPosition()] = std::make_shared<TrafficLightCell>();
	roadSystem[road.GetSecondTrafficLightPosition()] = std::make_shared<TrafficLightCell>();
}


void RoadSystem::SetUpTrafficLightPairs()
{
	SetUpFirstTrafficLightPair();
	SetUpSecondTrafficLightPair();
	SetUpThirdTrafficLightPair();
	SetUpFourthTrafficLightPair();
}


void RoadSystem::SetUpFirstTrafficLightPair()
{
	firstTrafficLightPair = TrafficLightPair(roadSystem[firstRoad.GetFirstTrafficLightPosition()], roadSystem[thirdRoad.GetFirstTrafficLightPosition()]);
}


void RoadSystem::SetUpSecondTrafficLightPair()
{
	secondTrafficLightPair = TrafficLightPair(roadSystem[secondRoad.GetFirstTrafficLightPosition()], roadSystem[thirdRoad.GetSecondTrafficLightPosition()]);
}


void RoadSystem::SetUpThirdTrafficLightPair()
{
	thirTrafficLightPair = TrafficLightPair(roadSystem[firstRoad.GetSecondTrafficLightPosition()], roadSystem[fourthRoad.GetFirstTrafficLightPosition()]);
}


void RoadSystem::SetUpFourthTrafficLightPair()
{
	fourthTrafficLightPair = TrafficLightPair(roadSystem[secondRoad.GetSecondTrafficLightPosition()], roadSystem[fourthRoad.GetSecondTrafficLightPosition()]);
}

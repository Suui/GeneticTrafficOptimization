#include "RoadSystem.h"
#include "Road.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"


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
	std::shared_ptr<TrafficLightCell> first = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[firstRoad.GetFirstTrafficLightPosition()]);
	std::shared_ptr<TrafficLightCell> second = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[thirdRoad.GetFirstTrafficLightPosition()]);

	if (first && second)
		firstTrafficLightPair = TrafficLightPair(first, second);
}


void RoadSystem::SetUpSecondTrafficLightPair()
{
	std::shared_ptr<TrafficLightCell> first = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[secondRoad.GetFirstTrafficLightPosition()]);
	std::shared_ptr<TrafficLightCell> second = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[thirdRoad.GetSecondTrafficLightPosition()]);

	if (first && second)
		secondTrafficLightPair = TrafficLightPair(first, second);
}


void RoadSystem::SetUpThirdTrafficLightPair()
{
	std::shared_ptr<TrafficLightCell> first = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[firstRoad.GetSecondTrafficLightPosition()]);
	std::shared_ptr<TrafficLightCell> second = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[fourthRoad.GetFirstTrafficLightPosition()]);

	if (first && second)
		thirTrafficLightPair = TrafficLightPair(first, second);
}


void RoadSystem::SetUpFourthTrafficLightPair()
{
	std::shared_ptr<TrafficLightCell> first = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[secondRoad.GetSecondTrafficLightPosition()]);
	std::shared_ptr<TrafficLightCell> second = std::dynamic_pointer_cast<TrafficLightCell>(roadSystem[fourthRoad.GetSecondTrafficLightPosition()]);

	if (first && second)
		fourthTrafficLightPair = TrafficLightPair(first, second);
}

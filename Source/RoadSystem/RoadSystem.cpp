#include "RoadSystem.h"
#include "Road.h"
#include "../Cells/EntryCell.h"
#include "../Cells/ExitCell.h"
#include "../Cells/TrafficLightCell.h"
#include "../Parsers/BinaryCycleParser.h"


void RoadSystem::PerformStep()
{
	AdvanceVehiclesInRoad(firstRoad);
	AdvanceVehiclesInRoad(secondRoad);
	AdvanceVehiclesInRoad(thirdRoad);
	AdvanceVehiclesInRoad(fourthRoad);
}


void RoadSystem::AdvanceVehiclesInRoad(Road& road)
{
	std::vector<Position> positions = road.GetPositions();

	roadSystem[road.GetExitCellPosition()]->VehicleExit();

	Position currentPos, lastPos;
	for (int i = positions.size() - 2; i >= 0; i--)
	{
		currentPos = positions[i];
		lastPos = positions[i + 1];

		roadSystem[currentPos]->AddVehicleMovement(0);

		if (roadSystem[currentPos]->GetState() == Empty) continue;

		if (roadSystem[currentPos]->GetTrafficLightState() == Red) continue;

		if (roadSystem[lastPos]->IsOccupied()) continue;
		
		if (road.GetDirection() == Vertical && roadSystem[currentPos]->GetState() == HorizontallyOccupied) continue;
		
		if (road.GetDirection() == Horizontal && roadSystem[currentPos]->GetState() == VerticallyOccupied) continue;

		road.GetDirection() == Vertical ? roadSystem[lastPos]->SetState(VerticallyOccupied) 
			                            : roadSystem[lastPos]->SetState(HorizontallyOccupied);
		
		roadSystem[currentPos]->SetState(Empty);
	}
}


void RoadSystem::AddVehiclesInEntryCells()
{
	roadSystem[firstRoad.GetEntryCellPosition()]->AddVehicle();
	roadSystem[secondRoad.GetEntryCellPosition()]->AddVehicle();
	roadSystem[thirdRoad.GetEntryCellPosition()]->AddVehicle();
	roadSystem[fourthRoad.GetEntryCellPosition()]->AddVehicle();
}


void RoadSystem::UpdateTrafficLights()
{
	firstTrafficLightPair.UpdateState();
	secondTrafficLightPair.UpdateState();
	thirdTrafficLightPair.UpdateState();
	fourthTrafficLightPair.UpdateState();
}


void RoadSystem::ResetExitedVehicles()
{
	roadSystem[firstRoad.GetExitCellPosition()]->ResetExitCout();
	roadSystem[secondRoad.GetExitCellPosition()]->ResetExitCout();
	roadSystem[thirdRoad.GetExitCellPosition()]->ResetExitCout();
	roadSystem[fourthRoad.GetExitCellPosition()]->ResetExitCout();
}


int RoadSystem::GetExitedVehicles()
{
	return roadSystem[firstRoad.GetExitCellPosition()]->GetExitCount()
		 + roadSystem[secondRoad.GetExitCellPosition()]->GetExitCount()
		 + roadSystem[thirdRoad.GetExitCellPosition()]->GetExitCount()
		 + roadSystem[fourthRoad.GetExitCellPosition()]->GetExitCount();
}


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
		roadSystem[pos] = std::make_shared<Cell>(road.GetDirection());

	roadSystem[road.GetEntryCellPosition()] = std::make_shared<EntryCell>(road.GetDirection());
	roadSystem[road.GetExitCellPosition()] = std::make_shared<ExitCell>(road.GetDirection());
	roadSystem[road.GetFirstTrafficLightPosition()] = std::make_shared<TrafficLightCell>(road.GetDirection());
	roadSystem[road.GetSecondTrafficLightPosition()] = std::make_shared<TrafficLightCell>(road.GetDirection());
}


void RoadSystem::SetUpTrafficLightPairs()
{
	SetUpFirstTrafficLightPair();
	SetUpSecondTrafficLightPair();
	SetUpThirdTrafficLightPair();
	SetUpFourthTrafficLightPair();
}


void RoadSystem::SetTrafficLightCycles(std::vector<int> binaryCycle)
{
	BinaryCycleParser parser = BinaryCycleParser(binaryCycle);

	firstTrafficLightPair.SetBinaryCycle(parser.GetFirst());
	secondTrafficLightPair.SetBinaryCycle(parser.GetSecond());
	thirdTrafficLightPair.SetBinaryCycle(parser.GetThird());
	fourthTrafficLightPair.SetBinaryCycle(parser.GetFourth());
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
	thirdTrafficLightPair = TrafficLightPair(roadSystem[firstRoad.GetSecondTrafficLightPosition()], roadSystem[fourthRoad.GetFirstTrafficLightPosition()]);
}


void RoadSystem::SetUpFourthTrafficLightPair()
{
	fourthTrafficLightPair = TrafficLightPair(roadSystem[secondRoad.GetSecondTrafficLightPosition()], roadSystem[fourthRoad.GetSecondTrafficLightPosition()]);
}

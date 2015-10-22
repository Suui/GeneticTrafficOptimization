﻿#include "RoadSystem.h"
#include "Road.h"
#include "../Exceptions/NotImplementedException.h"


RoadSystem& RoadSystem::WithFirstRoad(Road road)
{
	firstRoad = road;
	for (auto it = firstRoad.Begin(); it != firstRoad.End(); ++it)
	{
		roadSystem.insert(std::make_pair(it->first, *it->second));
		firstRoad[it->first] = std::make_shared<Cell>(roadSystem[it->first]);
	}

	return *this;
}


RoadSystem& RoadSystem::WithSecondRoad(Road road)
{
	secondRoad = road;
	for (auto it = secondRoad.Begin(); it != secondRoad.End(); ++it)
	{
		roadSystem.insert(std::make_pair(it->first, *it->second));
		secondRoad[it->first] = std::make_shared<Cell>(roadSystem[it->first]);
	}

	return *this;
}


RoadSystem& RoadSystem::WithThirdRoad(Road road)
{
	thirdRoad = road;
	for (auto it = thirdRoad.Begin(); it != thirdRoad.End(); ++it)
	{
		roadSystem.insert(std::make_pair(it->first, *it->second));
		thirdRoad[it->first] = std::make_shared<Cell>(roadSystem[it->first]);
	}

	return *this;
}


RoadSystem& RoadSystem::WithFourthRoad(Road road)
{
	throw NotImplementedException();
}

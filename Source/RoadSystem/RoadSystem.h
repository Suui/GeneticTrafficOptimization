#pragma once


class Road;

class RoadSystem
{


public:

	RoadSystem();

	RoadSystem build();

	RoadSystem WithFirstRoad(Road road);

	RoadSystem WithSecondRoad(Road road);

	RoadSystem WithThirdRoad(Road road);

	RoadSystem WithFourthRoad(Road road);

	Road GetFirstRoad();
};

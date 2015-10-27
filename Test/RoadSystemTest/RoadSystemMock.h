#pragma once
#include <RoadSystem/RoadSystem.h>


class RoadSystemMock : public RoadSystem
{

public:

	RoadSystemMock& WithFirstRoad(Road road) override;
	
	RoadSystemMock& WithSecondRoad(Road road) override;
	
	RoadSystemMock& WithThirdRoad(Road road) override;
	
	RoadSystemMock& WithFourthRoad(Road road) override;
	
	Road& GetFirstRoad() { return firstRoad; }
	
	Road& GetSecondRoad() { return secondRoad; }
	
	Road& GetThirdRoad() { return thirdRoad; }
	
	Road& GetFourthRoad() { return fourthRoad; }
	
	int Length() const { return roadSystem.size(); }

	TrafficLightPair GetFirstTrafficLightPair() { return firstTrafficLightPair; }
};

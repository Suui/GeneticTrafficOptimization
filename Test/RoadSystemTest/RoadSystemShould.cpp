#include "../TestRunner/catch.hpp"
#include <RoadSystem/RoadSystem.h>
#include <Builders/RoadBuilder.h>


TEST_CASE("Road System Should")
{
	SECTION("be constructed correctly")
	{
		RoadSystem roadSystem = RoadSystem()
								.WithFirstRoad	(RoadBuilder::BuildFirstRoad())
								.WithSecondRoad	(RoadBuilder::BuildSecondRoad())
								.WithThirdRoad	(RoadBuilder::BuildThirdRoad())
								.WithFourthRoad	(RoadBuilder::BuildFourthRoad());
		
		roadSystem.SetUpTrafficLightPairs();
	}
}
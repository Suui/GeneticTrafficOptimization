#include "../TestRunner/catch.hpp"
#include <RoadSystem/Road.h>


TEST_CASE("Road Should")
{
	GIVEN("A builder that stops at the From function")
	{
		Road testRoad = Road().From(0, 4);

		THEN("return a length of 1")
		{
			CHECK(testRoad.Length() == 1);
		}
	}

	GIVEN("A builder that stops at the To function")
	{
		Road testRoad = Road().From(0, 4).To(13, 4);

		THEN("return the correct length")
		{
			CHECK(testRoad.Length() == 14);
		}
	}

	GIVEN("A builder that stops at the WithFirstTrafficLight function")
	{
		Road testRoad = Road().From(0, 4).To(13, 4).WithFirstTrafficLightIn(3, 4);
		REQUIRE(testRoad.Length() == 14);

		THEN("return the first Traffic Light at the correct position")
		{
			CHECK(testRoad.GetFirstTrafficLightPosition() == Position(3, 4));
		}
	}

	GIVEN("A builder that stops at the WithSecondTrafficLight function")
	{
		Road testRoad = Road().From(0, 4).To(13, 4).WithFirstTrafficLightIn(3, 4).WithSecondTrafficLight(8, 4);
		REQUIRE(testRoad.Length() == 14);

		THEN("return the first and second Traffic Light at the correct positions")
		{
			CHECK(testRoad.GetFirstTrafficLightPosition() == Position(3, 4));
			CHECK(testRoad.GetSecondTrafficLightPosition() == Position(8, 4));
		}

		THEN("return the Entry Cell and the Exit Cell positions")
		{
			CHECK(testRoad.GetEntryCellPosition() == Position(0, 4));
			CHECK(testRoad.GetExitCellPosition() == Position(13, 4));
		}
	}
}
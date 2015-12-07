#include "../TestRunner/catch.hpp"
#include "ParetoDataStub.h"
#include <Simulation/Simulator.h>
#include <Builders/BinaryCycleBuilder.h>


TEST_CASE("ParetoData should")
{
	SECTION("Return the correct average GHG")
	{
		ParetoDataStub paretoData;

		std::map<int, std::vector<int>> data = { std::make_pair(0, std::vector<int> { 0, 1, 0, 0, 1, 1} ),
												 std::make_pair(1, std::vector<int> { 1, 1, 0, 1, 0, 1} ) };
												 
		paretoData.StubSetGasData(data);

		CHECK(paretoData.GetGHGAverage() == 2);
	}

	GIVEN("a simulator")
	{
		Simulator simulator;

		WHEN("it has random traffic light cycles and 200 steps")
		{
			simulator.SetTrafficLightCycles(BinaryCycleBuilder::BuildChangingAllTheTime());
			simulator.SetSimulationSteps(200);

			THEN("should correctly return an average GHG")
			{
				simulator.Simulate();

				CHECK(simulator.GetAverageGHGForLastSimulation() == 20);
			}
		}
	}
}
#include "../TestRunner/catch.hpp"
#include <Builders/BinaryCycleBuilder.h>
#include <Simulation/Simulator.h>


SCENARIO("Simulator should")
{
	GIVEN("the simulator")
	{
		Simulator simulator;
		
		WHEN("we perform 13 simulation steps and Traffic Lights don't change")
		{
			simulator.SetSimulationSteps(13);
			simulator.SetTrafficLightCycles(BinaryCycleBuilder::BuildWithoutChange());

			THEN("have 0 vehicles that have exited")
			{
				simulator.Simulate();
				CHECK(simulator.GetExitedVehiclesForLastSimulation() == 0);
			}
		}

		WHEN("we perform 14 simulation steps and Traffic Lights don't change")
		{
			simulator.SetSimulationSteps(14);
			simulator.SetTrafficLightCycles(BinaryCycleBuilder::BuildWithoutChange());
		
			THEN("have 2 vehicles that have exited after 15 simulation steps")
			{
				simulator.Simulate();
				CHECK(simulator.GetExitedVehiclesForLastSimulation() == 2);
			}
		}

		WHEN("we perform 18 simulation steps and Traffic Lights don't change")
		{
			simulator.SetSimulationSteps(18);
			simulator.SetTrafficLightCycles(BinaryCycleBuilder::BuildWithoutChange());

			THEN("have 2 vehicles that have exited after 15 simulation steps")
			{
				simulator.Simulate();
				CHECK(simulator.GetExitedVehiclesForLastSimulation() == 2);
			}
		}

		WHEN("we perform 18 simulation steps and Traffic Lights don't change")
		{
			simulator.SetSimulationSteps(19);
			simulator.SetTrafficLightCycles(BinaryCycleBuilder::BuildWithoutChange());

			THEN("have 2 vehicles that have exited after 15 simulation steps")
			{
				simulator.Simulate();
				CHECK(simulator.GetExitedVehiclesForLastSimulation() == 4);
			}
		}
	}
}
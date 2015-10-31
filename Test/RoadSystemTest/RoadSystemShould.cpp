﻿
/**
	A Traffic System which is composed of 4 roads. [OK]
	- Two vertical ones and two horizontal ones.
	
			       1         2
			       _         _
			      |I|       |I|
			      |_|       |_|
			      |_|       |_|
		   _ _ _ _|T|_ _ _ _|T|_ _ _ _
		3 |I|_|_|T|_|_|_|_|T|_|_|_|_|E|			I: Entry point
		          |_|       |_|
		          |_|       |_|					E: Exit point
		          |_|		|_|
		   _ _ _ _|T|_ _ _ _|T|_ _ _ _			T: Traffic Light
		4 |I|_|_|T|_|_|_|_|T|_|_|_|_|E|
		          |_|       |_|
		          |_|       |_|
		          |_|       |_|
		          |E|       |E|
	
	- Each road has 14 cells or fields.
	- Each road has two traffic lights, at index 3 and 8.
	
	The traffic lights are arranged by pairs. [OK]
	- Road 1 @[3] && Road 3 @[3]
	- Road 2 @[3] && Road 3 @[8]
	- Road 1 @[8] && Road 4 @[3]
	- Road 2 @[8] && Road 4 @[8]
	- When one is green, the other is red. No orange light is supported.
	
	Each cell may be free or occupied by a vehicle.
	- Vehicles can't turn, they just go straight in their road.
	- Vehicles stop at the red light (in the same cell where the Traffic Light is located).
	- Vehicles just advance 1 cell per simulation step.
	- A new vehicle enters each road every 5 simulation steps. He tries to enter his assigned
	  road in the Entry point, however if the Entry point is occupied, it will get into the
	  queue for that road and wait his turn to enter it.
	- A vehicle exits his assigned road over the Exit point.
	
	Simulation requirements.
	- A simulation step is equivalent to 1 second.
	- An entire simulation has 7200 simulation steps (2 hours).
	- The Traffic Lights may change or not their state once every 10 simulation steps.
	- The Traffic Lights maintain their time between red and green over the whole simulation.
	
	Objective.
	- We want to get the best traffic control result as determined by the number of
	  vehicles who exit the roads in an entire simulation (which is the Fitness).
	- The Traffic Lights are the only thing we will take into account when deciding
	  the optimal traffic control.
	- So, the optimization will be directed by the Traffic Lights with a cycle of 120 simulation
	  steps (2 minutes), where they will have 12 possible states (they can change once every 10 simulation steps).
	- 4 pairs means 4 x 12 = 48 states over the whole traffic system in those 120 simulation steps.
	- We are determining that the cromosome will have 48 states. A state can be represented by 1 bit,
	  where 0 == green-red and 1 == red-green. Then, 48 bits.
	- To further explain, every 10 simulation steps the Traffic Light pairs will be set to a state,
	  they can stay the same or change, which is determined by their corresponding 12 bits.
	
	The result of those state changes that get repeated every 120 simulation steps (2 minutes) will
	affect the number of vehicles leaving the traffic system. The total number of the vehicles that
	could exit is our Fitness to compare the cromosome against others.
	
	
	Notes for my aproach.
	- 48 bits mean 48^2 = 2304 possible combinations available.
	- The whole simulation has a high cost and will take some time.
	- Maybe use the tournament selection mode.
	- Still don't know what reproduction technique to apply.
*/


/**
	TODO list.
	- We need 4 roads which are mixed.
	- We need 4 pairs of Traffic Lights.
	- It's important that the cells where the roads cross belong to both roads.
	- The structure we'll be following is a hashmap that simulates an 2D array without
	  the unnecessary cells.
	- The structure created is [NOT FLEXIBLE].
	
	Possible Tests.
	- GetFirstRoad		=> { (0, 4) .. (13, 4) }
	- GetSecondRoad		=> { (0, 9) .. (13, 9) }
	- GetThirdRoad		=> { (4, 0) .. (4, 13) }
	- GetFourthRoad		=> { (9, 0) .. (9, 13) }
	
	- GetFullRoadSystem =>
	
	- GetFirstTrafficLightPair		=>	(3, 4) && (4, 3)
	- GetSecondTrafficLightPair		=>	(3, 9) && (4, 8)
	- GetThirdTrafficLightPair		=>	(8, 4) && (9, 3)
	- GetFourthTrafficLightPair		=>	(8, 9) && (9, 8)
	
	- GetFirstRoad().GetQueue()
	- GetFirstRoad().GetNumberOfVehiclesWhoLeftTheRoad()
	- GetFirstRoad().GetFirstTrafficLight()
	
*/


#include "../TestRunner/catch.hpp"
#include <RoadSystem/RoadSystem.h>
#include <Builders/RoadBuilder.hpp>
#include <Builders/BinaryCycleBuilder.h>


SCENARIO("Road System Should")
{
	GIVEN("a Road System that doesn't change Traffic Light colors")
	{
		RoadSystem roadSystem = RoadSystem()
								.WithFirstRoad	(RoadBuilder::BuildFirstRoad())
								.WithSecondRoad	(RoadBuilder::BuildSecondRoad())
								.WithThirdRoad	(RoadBuilder::BuildThirdRoad())
								.WithFourthRoad	(RoadBuilder::BuildFourthRoad());
		
		roadSystem.SetUpTrafficLightPairs();
	}
}
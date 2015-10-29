#pragma once

#include "RoadSystem/RoadSystem.h"


class Simulator
{
	RoadSystem roadSystem;
	const int SIMULATION_LENGTH = 7200;


public:

	Simulator();

	void Simulate();
};

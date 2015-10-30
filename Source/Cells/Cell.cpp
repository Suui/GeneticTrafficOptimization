#include "Cell.h"


Cell::Cell(Direction direction) : direction(direction)
{
	state = Empty;
	trafficLightState = Green;
	entryQueue = 0;
	exitCount = 0;
	vehicle = nullptr;
}


int Cell::vehicleID = 0;

#include "Cell.h"
#include "../ParetoData/ParetoData.h"


Cell::Cell(Direction direction) : direction(direction)
{
	state = Empty;
	trafficLightState = Green;
	entryQueue = 0;
	exitCount = 0;
	vehicle = nullptr;
}

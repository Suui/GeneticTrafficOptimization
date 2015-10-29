#include "Cell.h"


Cell::Cell()
{
	state = Empty;
	trafficLightState = Red;
	entryQueue = 0;
	exitCount = 0;
}
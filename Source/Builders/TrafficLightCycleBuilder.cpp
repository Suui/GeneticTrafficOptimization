#include "TrafficLightCycleBuilder.h"


TrafficLightCycle TrafficLightCycleBuilder::Build()
{
	std::vector<int> init = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
							  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
							  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
							  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
	return TrafficLightCycle(init);
}
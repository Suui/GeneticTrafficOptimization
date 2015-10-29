#include "TrafficLightPair.h"


void TrafficLightPair::SwitchTrafficLightStates()
{
	if (first->GetTrafficLightState() == Green)
	{
		first->SetTrafficLightState(Red);
		second->SetTrafficLightState(Green);
	}
	else
	{
		first->SetTrafficLightState(Green);
		second->SetTrafficLightState(Red);
	}
}


void TrafficLightPair::UpdateState()
{
	if (binaryCycle[cycleIndex] == 1) SwitchTrafficLightStates();
	
	cycleIndex = (cycleIndex + 1) % 12;
}

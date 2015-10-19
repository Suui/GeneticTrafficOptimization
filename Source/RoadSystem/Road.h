#pragma once

class TrafficLight;

class Road
{

public:

	Road();

	Road build();

	Road From(int x, int y);
	
	Road To(int x, int y);

	Road WithFirstTrafficLightIn(int x, int y);

	Road WithSecondTrafficLight(int x, int y);
	
	int Length();

	TrafficLight GetFirstTrafficLight();
};

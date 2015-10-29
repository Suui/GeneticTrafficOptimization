#pragma once

#include "../RoadSystem/Road.h"


class RoadBuilder
{

public:

	static Road BuildFirstRoad() { return Road().From(0, 4).To(13, 4).WithFirstTrafficLightIn(3, 4).WithSecondTrafficLight(8, 4).WithDirection(Vertical); }

	static Road BuildSecondRoad() { return Road().From(0, 9).To(13, 9).WithFirstTrafficLightIn(3, 9).WithSecondTrafficLight(8, 9).WithDirection(Vertical); }

	static Road BuildThirdRoad() { return Road().From(4, 0).To(4, 13).WithFirstTrafficLightIn(4, 3).WithSecondTrafficLight(4, 8).WithDirection(Horizontal); }

	static Road BuildFourthRoad() { return Road().From(9, 0).To(9, 13).WithFirstTrafficLightIn(9, 3).WithSecondTrafficLight(9, 8).WithDirection(Horizontal); }
};
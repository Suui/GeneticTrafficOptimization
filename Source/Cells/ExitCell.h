#pragma once

#include "Cell.h"


class ExitCell : Cell
{
public:

	ExitCell() { Cell(); exitCount = 0; }

	bool isExitCell() override { return true; }

	void VehicleExit() override
	{
		if (state == Occupied)
		{
			exitCount += 1;
			state = Empty;
		}
	}
};

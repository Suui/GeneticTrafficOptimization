#pragma once

#include "Cell.h"


class ExitCell : public Cell
{

public:

	ExitCell(Direction direction) : Cell(direction) {}

	void VehicleExit() override
	{
		if (IsOccupied())
		{
			exitCount += 1;
			state = Empty;
			vehicle.reset();
		}
	}

	void ResetExitCount() override { exitCount = 0; }
};

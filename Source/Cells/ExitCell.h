#pragma once

#include "Cell.h"


class ExitCell : public Cell
{

public:

	ExitCell(Direction direction) : Cell(direction) {}

	bool isExitCell() override { return true; }

	void VehicleExit() override
	{
		if (IsOccupied())
		{
			exitCount += 1;
			state = Empty;
		}
	}
};

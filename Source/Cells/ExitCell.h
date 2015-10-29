#pragma once

#include "Cell.h"


class ExitCell : public Cell
{

public:

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

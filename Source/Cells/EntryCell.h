#pragma once

#include "Cell.h"


class EntryCell : Cell
{

public:

	EntryCell() { Cell(); entryQueue = 0; }

	bool isEntryCell() override { return true; }
	
	void SetState(CellState& state) override { state == Empty && entryQueue > 0 ? entryQueue -= 1 : this->state = Empty; }
	
	void AddVehicle() override { entryQueue > 0 ? entryQueue += 1 : this->state = Occupied; }
};

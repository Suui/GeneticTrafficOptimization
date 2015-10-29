#pragma once

#include "Cell.h"


class EntryCell : public Cell
{

public:

	EntryCell(Direction direction) : Cell(direction) {}

	bool isEntryCell() override { return true; }
	
	void SetState(CellState state) override { state == Empty && entryQueue > 0 ? entryQueue -= 1 : this->state = Empty; }
	
	void AddVehicle() override 
	{ 
		if (entryQueue > 0)
			entryQueue += 1;
		else
			direction == Vertical ? this->state = VerticallyOccupied : this->state = HorizontallyOccupied;
	}
};

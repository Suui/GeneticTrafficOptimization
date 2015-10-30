#pragma once

#include "Cell.h"
#include <queue>


class EntryCell : public Cell
{
	std::queue<std::shared_ptr<Vehicle>> vehicleQueue;


public:

	EntryCell(Direction direction) : Cell(direction) {}

	bool isEntryCell() override { return true; }
	
	void SetState(CellState state) override 
	{
		if (state == Empty && vehicleQueue.size() > 0)
		{
			vehicle = vehicleQueue.front();
			vehicleQueue.pop();
		}
		else
			this->state = Empty;
	}
	
	void AddVehicle() override 
	{ 
		vehicleQueue.push(std::make_shared<Vehicle>(vehicleID));
		vehicleID += 1;

		if (IsOccupied()) return;

		direction == Vertical ? this->state = VerticallyOccupied : this->state = HorizontallyOccupied;
		vehicle = vehicleQueue.front();
		vehicleQueue.pop();
	}
};

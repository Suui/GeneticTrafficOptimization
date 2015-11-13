#pragma once

#include "Cell.h"
#include <queue>


class EntryCell : public Cell
{
	std::queue<std::shared_ptr<Vehicle>> vehicleQueue;


public:

	EntryCell(Direction direction) : Cell(direction) {}

	void SetState(CellState state) override;

	void AddVehicle() override;

	void ResetQueue() override 
	{ 
		std::queue<std::shared_ptr<Vehicle>> emptyQueue;
		vehicleQueue.swap(emptyQueue);
	}
};

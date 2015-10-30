#include "EntryCell.h"


void EntryCell::SetState(CellState state)
{
	if (state == Empty && vehicleQueue.size() > 0)
	{
		vehicle = vehicleQueue.front();
		vehicleQueue.pop();
	}
	else
		this->state = Empty;
}


void EntryCell::AddVehicle()
{ 
	vehicleQueue.push(std::make_shared<Vehicle>(vehicleID));
	vehicleID += 1;

	if (IsOccupied()) return;

	direction == Vertical ? this->state = VerticallyOccupied : this->state = HorizontallyOccupied;
	vehicle = vehicleQueue.front();
	vehicleQueue.pop();
}
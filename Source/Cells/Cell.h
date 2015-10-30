#pragma once
#include "../ParetoData/Vehicle.h"
#include <memory>


enum CellState
{
	Empty,
	VerticallyOccupied,
	HorizontallyOccupied
};


enum TrafficLightState
{
	Red,
	Green
};


enum Direction
{
	Vertical,
	Horizontal
};


class Cell
{

protected:

	CellState state;
	TrafficLightState trafficLightState;
	Direction direction;
	int entryQueue, exitCount;
	std::shared_ptr<Vehicle> vehicle;
	static int vehicleID;


public:

	Cell(Direction direction);

	virtual ~Cell() {}

	bool IsOccupied() { return state > 0; }

	virtual CellState& GetState() { return state; }

	virtual void SetState(CellState state) { this->state = state; }

	Direction GetDirection() { return direction; }

	std::shared_ptr<Vehicle>& GetVehicle() { return vehicle; }

	void SetVehicle(std::shared_ptr<Vehicle>& vehicle) { this->vehicle = vehicle; }

	virtual bool isEntryCell() { return false; }

	virtual void AddVehicle() {}

	virtual bool isExitCell() { return false; }

	virtual void VehicleExit() {}

	virtual bool isTrafficLight() { return false; }

	virtual TrafficLightState& GetTrafficLightState() { return trafficLightState; }

	int GetExitCount() { return exitCount; }

	virtual void SetTrafficLightState(TrafficLightState trafficLightState) { this->trafficLightState = trafficLightState; }

	virtual void ResetExitCout() {}

	void AddVehicleMovement(int movement) {  if (vehicle) vehicle->AddMovement(movement); }
};

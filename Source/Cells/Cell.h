#pragma once

#include "../ParetoData/Vehicle.h"
#include "../ParetoData/ParetoData.h"
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
	
	bool IsEmpty() { return state == 0; }

	bool IsOccupied() { return state > 0; }

	bool HasRedTrafficLight() { return trafficLightState == Red; }

	virtual CellState& GetState() { return state; }

	virtual void SetState(CellState state) { this->state = state; }

	Direction GetDirection() { return direction; }

	void FillVehicleGasDataIn(ParetoData& gasData) { if (vehicle) gasData.AddDataFrom(vehicle); }

	std::shared_ptr<Vehicle>& GetVehicle() { return vehicle; }

	void CarHasMoved() { vehicle->SetlastMovement(1); }

	void SetVehicle(std::shared_ptr<Vehicle>& vehicle) { this->vehicle = vehicle; }

	void ResetVehicle() { vehicle.reset(); }

	virtual void AddVehicle() {}

	virtual void VehicleExit() {}

	virtual TrafficLightState& GetTrafficLightState() { return trafficLightState; }

	int GetExitCount() { return exitCount; }

	virtual void SetTrafficLightState(TrafficLightState trafficLightState) { this->trafficLightState = trafficLightState; }

	virtual void ResetExitCount() {}

	void CarIsIdle() {  if (vehicle) vehicle->AddMovement(0); }
};

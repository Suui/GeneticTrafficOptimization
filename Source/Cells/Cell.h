#pragma once


enum CellState
{
	Empty,
	Occupied
};


enum TrafficLightState
{
	Red,
	Green
};


class Cell
{

protected:

	CellState state;
	TrafficLightState trafficLightState;
	int entryQueue, exitCount;


public:

	Cell();

	virtual ~Cell() {}

	virtual CellState& GetState() { return state; }

	virtual void SetState(CellState state) { this->state = state; }

	virtual bool isEntryCell() { return false; }

	virtual void AddVehicle() {}

	virtual bool isExitCell() { return false; }

	virtual void VehicleExit() {}

	virtual bool isTrafficLight() { return false; }

	virtual TrafficLightState& GetTrafficLightState() { return trafficLightState; };

	virtual void SetTrafficLightState(TrafficLightState trafficLightState) { this->trafficLightState = trafficLightState; }
};

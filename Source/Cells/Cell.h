#pragma once


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


public:

	Cell(Direction direction);

	virtual ~Cell() {}

	bool IsOccupied() { return state > 0; }

	virtual CellState& GetState() { return state; }

	virtual void SetState(CellState state) { this->state = state; }

	Direction GetDirection() { return direction; }

	virtual bool isEntryCell() { return false; }

	virtual void AddVehicle() {}

	virtual bool isExitCell() { return false; }

	virtual void VehicleExit() {}

	virtual bool isTrafficLight() { return false; }

	virtual TrafficLightState& GetTrafficLightState() { return trafficLightState; }

	int GetExitCount() { return exitCount; }

	virtual void SetTrafficLightState(TrafficLightState trafficLightState) { this->trafficLightState = trafficLightState; }
};

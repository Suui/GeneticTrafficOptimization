#pragma once


enum CellState
{
	Empty,
	Occupied,
};


struct Cell
{
	Cell();

	virtual ~Cell() {}
};

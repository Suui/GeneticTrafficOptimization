#pragma once


class Position
{
	const int x, y;

public:

	Position(int x, int y);


	friend bool operator==(const Position& a, const Position& b);

	friend bool operator!=(const Position& a, const Position& b);
};

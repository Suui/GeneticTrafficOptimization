#pragma once


struct Position
{
	Position() { x = 0; y = 0; }

	Position(int x, int y) : x(x), y(y) {}

	friend bool operator==(const Position& a, const Position& b) { return a.x == b.x && a.y == b.y; }

	friend bool operator!=(const Position& a, const Position& b) { return !(a == b); }

	friend bool operator<(const Position& a, const Position& b)
	{
		if (a.x < b.x)
			return true;
		if (b.x < a.x)
			return false;
		return a.y < b.y;
	}

	friend bool operator<=(const Position& a, const Position& b) { return !(b < a); }

	friend bool operator>(const Position& a, const Position& b) { return b < a; }

	friend bool operator>=(const Position& a, const Position& b) { return !(a < b); }

	int GetX() const { return x; }

	int GetY() const { return y; }

private:

	int x, y;
};

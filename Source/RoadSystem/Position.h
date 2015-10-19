#pragma once
#include <system_error>


struct Position
{
	Position() { x = 0; y = 0; }

	Position(int x, int y) : x(x), y(y) {}

	friend bool operator==(const Position& a, const Position& b) { return a.x == b.x && a.y == b.y; }

	friend bool operator!=(const Position& a, const Position& b) { return !(a == b); }
	
	int GetX() const { return x; }

	int GetY() const { return y; }

private:

	int x, y;
};


namespace std{

	template<>
	struct hash<Position>
	{
		size_t operator()(const Position& pos) const
		{
			return pos.GetX() * 20 + pos.GetY();
		}
	};
}

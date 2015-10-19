#include "Position.h"


Position::Position(int x, int y): x(x),
                                  y(y)
{
}


bool operator==(const Position& a, const Position& b)
{
	return a.x == b.x && a.y == b.y;
}


bool operator!=(const Position& a, const Position& b)
{
	return !(a == b);
}

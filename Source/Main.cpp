#include "GeneticStrategies/Tournament.h"


int main()
{
	auto tournament = Tournament(30, 100);
	tournament.Execute();

	return 0;
}
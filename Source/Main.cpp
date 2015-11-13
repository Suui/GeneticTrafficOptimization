#include "GeneticStrategies/Tournament.h"


int main()
{
	Tournament tournament = Tournament(30, 100);
	tournament.Execute();

	return 0;
}
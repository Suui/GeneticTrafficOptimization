#include "GeneticStrategies/Tournament.h"


int main()
{
	Tournament tournament = Tournament(1000, 262144);
	tournament.Execute();

	return 0;
}
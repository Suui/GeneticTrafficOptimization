#include "GeneticStrategies/Tournament.h"


int main()
{
	Tournament tournament = Tournament(20, 262144);
	tournament.Execute();

	return 0;
}
#include "GeneticStrategies/Tournament.h"
#include "vld.h"


int main()
{
	Tournament tournament = Tournament(1, 100);
	tournament.Execute();

	return 0;
}
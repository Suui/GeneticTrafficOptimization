#include "GeneticStrategies/Tournament.h"


int main()
{
	Tournament tournament = Tournament(20, 100);
	tournament.Execute();
	
	std::getchar();
	return 0;
}
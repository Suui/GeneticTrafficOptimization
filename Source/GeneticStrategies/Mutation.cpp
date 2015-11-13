#include "Mutation.h"
#include "../Utility/Math.hpp"


void Mutation::MaybeMutate(std::vector<int>& binaryCycle)
{
	if (Math::RandomExclusive(100) < 50) return;

	int mutationIndex = Math::RandomExclusive(binaryCycle.size());
	
	if (binaryCycle[mutationIndex] == 0)
		binaryCycle[mutationIndex] = 1;
	else
		binaryCycle[mutationIndex] = 0;
}
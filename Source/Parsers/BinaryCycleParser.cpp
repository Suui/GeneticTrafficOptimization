#include "BinaryCycleParser.h"


BinaryCycleParser::BinaryCycleParser(std::vector<int>& binaryCycle)
{
	first	= std::vector<int>(binaryCycle.begin() + 00, binaryCycle.begin() + 12);
	second	= std::vector<int>(binaryCycle.begin() + 12, binaryCycle.begin() + 24);
	third	= std::vector<int>(binaryCycle.begin() + 24, binaryCycle.begin() + 36);
	fourth	= std::vector<int>(binaryCycle.begin() + 36, binaryCycle.begin() + 48);
}

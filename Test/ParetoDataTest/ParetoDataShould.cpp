#include "../TestRunner/catch.hpp"
#include "ParetoDataStub.h"


TEST_CASE("ParetoData should")
{
	SECTION("Return the correct average GHG")
	{
		ParetoDataStub paretoData;

		std::map<int, std::vector<int>> data = { std::make_pair(0, std::vector<int> { 0, 1, 0, 0, 1, 1} ),
												 std::make_pair(1, std::vector<int> { 1, 1, 0, 1, 0, 1} ) };
												 
		paretoData.StubSetGasData(data);

		CHECK(paretoData.GetGHGAverage() == 2);
	}
}
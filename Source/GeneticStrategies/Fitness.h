#pragma once

#include <vector>


struct Fitness
{
private:

	std::vector<int> binaryCycle;
	int fitness, exitedVehicles, averageGHG;


public:

	Fitness(std::vector<int>& binaryCycle, int& exitedVehicles, int& averageGHG) : binaryCycle(binaryCycle),
																				   exitedVehicles(exitedVehicles),
																				   averageGHG(averageGHG)
	{
		fitness = exitedVehicles;
	}

	std::vector<int>& GetBinaryCycle() { return binaryCycle; }

	int& GetFitness() { return fitness; }

	friend bool operator==(const Fitness& Lhs, const Fitness& Rhs)
	{
		return Lhs.fitness == Rhs.fitness;
	}

	friend bool operator!=(const Fitness& Lhs, const Fitness& Rhs)
	{
		return !(Lhs == Rhs);
	}

	friend bool operator<(const Fitness& Lhs, const Fitness& Rhs)
	{
		return Lhs.fitness < Rhs.fitness;
	}

	friend bool operator<=(const Fitness& Lhs, const Fitness& Rhs)
	{
		return !(Rhs < Lhs);
	}

	friend bool operator>(const Fitness& Lhs, const Fitness& Rhs)
	{
		return Rhs < Lhs;
	}

	friend bool operator>=(const Fitness& Lhs, const Fitness& Rhs)
	{
		return !(Lhs < Rhs);
	}
};

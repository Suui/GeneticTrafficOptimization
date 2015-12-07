#pragma once

#include <vector>


struct Fitness
{
private:

	std::vector<int> binaryCycle;
	double fitness, exitedVehicles, averageGHG;
	double MAX_EXITED_VEHICLES = 14372.0;


public:


	Fitness(std::vector<int>& binaryCycle, double& exitedVehicles, double& averageGHG) : binaryCycle(binaryCycle),
																				   exitedVehicles(exitedVehicles),
																				   averageGHG(averageGHG)
	{
		fitness = exitedVehicles / MAX_EXITED_VEHICLES * 0.5 + averageGHG / 2 * 0.5;
	}

	std::vector<int>& GetBinaryCycle() { return binaryCycle; }

	double& GetFitness() { return fitness; }

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

	double& GetAverageGHG() { return averageGHG; }
};

#pragma once

#include <vector>


struct Fitness
{
private:

	std::vector<int> binaryCycle;
	double fitness, exitedVehicles, averageGHG;
	double exitedVehiclesFitness, GHGFitness;
	double MAX_EXITED_VEHICLES = 14372.0;
	double MAX_AVERAGE = 1.4;


public:

	Fitness(std::vector<int>& binaryCycle, double& exitedVehicles, double& averageGHG) : binaryCycle(binaryCycle),
																						 exitedVehicles(exitedVehicles),
																						 averageGHG(averageGHG)
	{
		exitedVehiclesFitness = exitedVehicles / MAX_EXITED_VEHICLES;
		GHGFitness = averageGHG / MAX_AVERAGE;
		fitness = exitedVehiclesFitness * 0.5 + (1 - GHGFitness) * 0.5;
	}

	std::vector<int>& GetBinaryCycle() { return binaryCycle; }

	double& GetFitness() { return fitness; }

	double& GetAverageGHG() { return averageGHG; }

	double& GetExitedVehiclesFitness() { return exitedVehiclesFitness; }

	double& GetGHGFitness() { return GHGFitness; }

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

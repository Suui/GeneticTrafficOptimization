#pragma once

#include <vector>


struct FitnessBinaryCyclePair
{
private:

	std::vector<int>& binaryCycle;
	int& fitness;


public:

	FitnessBinaryCyclePair(std::vector<int>& binaryCycle, int& fitness)	: binaryCycle(binaryCycle),
																		  fitness(fitness)
	{}

	std::vector<int>& GetBinaryCycle() const { return binaryCycle; }

	int& GetFitness() const { return fitness; }


	friend bool operator==(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return Lhs.fitness == Rhs.fitness;
	}

	friend bool operator!=(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return !(Lhs == Rhs);
	}

	friend bool operator<(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return Lhs.fitness < Rhs.fitness;
	}

	friend bool operator<=(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return !(Rhs < Lhs);
	}

	friend bool operator>(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return Rhs < Lhs;
	}

	friend bool operator>=(const FitnessBinaryCyclePair& Lhs, const FitnessBinaryCyclePair& Rhs)
	{
		return !(Lhs < Rhs);
	}
};

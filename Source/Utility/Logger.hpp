#pragma once

#include <string>
#include <iostream>
#include <sstream>


class Logger
{

public:

	static void LogLine(std::string string) { std::cout << string << std::endl; }

	static void LogLine(double number)
	{
		std::ostringstream stream;
		stream << number;
		LogLine(stream.str());
	}
};

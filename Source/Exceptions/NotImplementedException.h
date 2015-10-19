#include <system_error>


class NotImplementedException : public std::exception
{
	std::string errorMessage;

public:

	NotImplementedException(const char * error = "The functionality has not been implemented yet")
	{
		errorMessage = error;
	}


	const char* what() const override
	{
		return errorMessage.c_str();
	}
};
#include <system_error>


class NotImplementedException : public std::exception
{
	std::string errorMessage;

public:

	NotImplementedException(const char * error = "Not implemented exception")
	{
		errorMessage = error;
	}


	const char* what() const override
	{
		return errorMessage.c_str();
	}
};
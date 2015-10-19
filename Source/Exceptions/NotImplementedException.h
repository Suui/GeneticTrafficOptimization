#include <system_error>


class NotImplementedException : public std::exception
{
	std::string errorMessage;

public:

	NotImplementedException(const char * error = "Functionality not yet implemented!")
	{
		errorMessage = error;
	}


	const char* what() const override
	{
		return errorMessage.c_str();
	}
};
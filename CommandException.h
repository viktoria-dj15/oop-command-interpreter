#ifndef COMMAND_EXCEPTION_H_
#define COMMAND_EXCEPTION_H_

#include "Exception.h"

// Specific exception for command execution errors.
class CommandException :public Exception{
public:

	CommandException(std::string message);
};

inline CommandException::CommandException(std::string message) {
	this->message = message;
}
#endif
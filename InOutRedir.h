#ifndef INOUTREDIR_H
#define INOUTREDIR_H
#include "Command.h"
#include "Reader.h"

// Class for commands that can have both input and output redirection. It inherits from Command and provides methods to handle both types of redirection.
class InOutRedir : public Command {
public:
	InOutRedir();

	//	Checks if there is an argument, then sets it as input.
	virtual void checkArgument(int& index, std::vector<std::string> tokens);

	//	Checks for redirection and sets input and output accordingly.
	virtual void redirect (int& index, std::vector<std::string> tokens);
};

inline InOutRedir::InOutRedir() : Command() {}

#endif
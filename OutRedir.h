#ifndef OUTREDIR_H
#define OUTREDIR_H

#include "Command.h"

// Class for commands that can have output redirection. 
class OutRedir : public Command {
public:
	OutRedir();

	void redirection(int& i, std::vector<std::string> tokens);

};

inline OutRedir::OutRedir() : Command() {}
#endif
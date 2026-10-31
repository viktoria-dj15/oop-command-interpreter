#ifndef PIPE_H
#define PIPE_H
#include <iostream>
#include "Command.h"
#include <string>
#include <list>

// Represents a list of commands connected by pipes.
class Pipe{
public:
	Pipe(std::ostream* output = &std::cout);

	~Pipe();

	// Runs the commands in the pipe sequentially, passing the output of each command as input to the next command.
	void runPipe();

	// Adds a command to the pipe.
	void addCommand(Command* cmd);

private:
	// Output stream to write the final output of the pipe.
	std::ostream* os;

	std::list<Command*> commands;
	std::list<Command*>::iterator it;

};

//Inline method definitions.
inline Pipe::Pipe(std::ostream* output) : commands(), it(commands.begin()), os(output) {}

inline Pipe::~Pipe() {
	for (auto cmd : commands) {
		delete cmd;
	}
}
#endif

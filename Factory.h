#ifndef FACTORY_H
#define FACTORY_H
#include "Lexer.h"
#include "Command.h"
#include "Pipe.h"
#include <iostream>
#include <fstream>

// Factory class. Responsible for creating commands and pipes based on the input line.
class Factory {
public:
	Factory(std::string line,std::ostream* out);

	~Factory();

	// Parses the input line and creates a Pipe with the appropriate commands and redirections.
	Pipe* produce();

private:
	// Helper function to create a Command object based on the command tokens.
	Command* makeCommand(std::vector<std::string> cmd_tokens);

	Lexer* lex;
	std::ostream* outp;

};
// Inline method definitions.

inline Factory::Factory(std::string line, std::ostream* outp) : outp(outp) {
	lex = new Lexer(line);
}

inline Factory::~Factory() {
	delete lex;
}

#endif
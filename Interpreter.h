#ifndef INTERPETER_H
#define INTERPETER_H
#include <string>
#include "Lexer.h"
#include "Factory.h"

// Singleton class for the interpreter. It manages the command prompt and runs the main loop of the program.
class Interpreter {
public:

	//	Returns the singleton instance of this class. Static.
	static Interpreter* Instance();

	//	Gets the command prompt.
	std::string getCommandPrompt() const;

	// Sets the command propmt.
	void setCommandPrompt(std::string s);


	// Runs the programm.
	void process();

	//	Method for Interpreter destruction. 
	void destroy();

private:

	//	Constructor.
	Interpreter();

	//	Destructor
	virtual ~Interpreter();

	static Interpreter* i_instance;
	std::string command_prompt;

};


//	Inline methods definiton.

inline Interpreter:: ~Interpreter() {}

inline std::string Interpreter::getCommandPrompt() const {
	return command_prompt;
}

inline void Interpreter::setCommandPrompt(std::string newCommPrompt) {
	command_prompt = newCommPrompt;
	return;
}

#endif
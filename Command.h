#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>
#include "SyntaxException.h"
#include "SemanticException.h"
#include "CommandException.h"
#include "Exception.h"

// Structure to hold output redirection information.
struct Output {
	std::string out;
	bool append;
};

// Abstract base class for all commands.
class Command {
public:
	Command();
	// Runs each command individually.
	virtual std::string run()=0;

	std::string  getName() const;

	// Parses the command and its arguments.
	virtual void parse(std::vector<std::string> token)=0;

	std::string getInput() const;

	Output getOutput() const;

	void setInput(std::string& in);

	// Checks if the token is a file name (not a quoted string).
	bool isFile(std::string token) const;

protected:
	//Helper. Checks if token is redirection.
	virtual bool isRedirection(std::string token) const;

	std::string input;
	Output output;

	std::string name;
};

inline Command::Command() : input(""), output({"", false}),name("") {}
inline std::string Command::getInput() const {
	return input;
}
inline std::string Command::getName() const {
	return name;
}

inline Output Command::getOutput() const {
	return output;
}

inline void Command::setInput(std::string& in) {
	input = in;
}

inline bool Command::isRedirection(std::string token) const {
	return token == ">" || token == ">>" || token == "<";
}

inline bool Command::isFile(std::string token) const {
	if (token.empty()) return false;
	else if (token[0] == '"' && token[token.size() - 1] == '"') return false;
	return true;
}

#endif
#ifndef PROMPT_H
#define PROMPT_H
#include "Interpreter.h"
#include "Command.h"

// Prompt command. Changes the command prompt of the interpreter.
class Prompt : public Command {
public:

	Prompt(std::vector<std::string> tokens);

	std::string run() override;

	virtual void parse(std::vector<std::string> tokens) override;

private:
	// Helper function to extract the new prompt from the argument, removing the quotes.
	std::string promptSign(std::string sign);

	// The new command prompt to be set in the interpreter.
	std::string new_prompt;
};

inline Prompt::Prompt(std::vector<std::string> tokens) {
	name = "prompt";
	parse(tokens);
}
inline void Prompt::parse(std::vector<std::string> tokens) {
	if (tokens.size() != 2) {
		throw SyntaxException("Prompt command requires exactly one argument.");
	}
	new_prompt = promptSign(tokens[1]);
}

inline std::string Prompt::run() {
	Interpreter::Instance()->setCommandPrompt(new_prompt);
	return "";
}
inline std::string Prompt::promptSign(std::string sign) {
	if (sign[0] != '"' && sign[sign.size() - 1] != '"') {
		throw SyntaxException("Prompt argument must be a quoted string.");
	}
	return sign.substr(1, sign.size() - 2) + " ";
}

#endif
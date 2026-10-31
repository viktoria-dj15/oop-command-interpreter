#include "Factory.h"
#include "FactoryIncludes.h"
using namespace std;


Pipe* Factory::produce() {
	std::vector<std::string> tokens = lex->getTokens();
	vector<string> cmd_tokens; // Tokens for the current command being processed.
	string input = "";
	Command* cmd;
	Pipe* p = new Pipe(outp);
	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "|") {
			cmd = makeCommand(cmd_tokens);
			p->addCommand(cmd);
			cmd_tokens.clear();
			continue;
		}
		cmd_tokens.push_back(tokens[i]);
	}
	cmd = makeCommand(cmd_tokens);
	p->addCommand(cmd);
	cmd_tokens.clear();
	return p;
}

Command* Factory::makeCommand(vector<string> cmd_tokens) {
	if (cmd_tokens.size() == 0) {
		throw SyntaxException("Empty command.");
		return nullptr;
	}
	if(cmd_tokens[0] == "echo"){
		return new Echo(cmd_tokens);
	}
	else if(cmd_tokens[0]=="batch"){
		return new Batch(cmd_tokens);
	}
	else if (cmd_tokens[0] == "touch") {
		return new Touch(cmd_tokens);
	}
	else if (cmd_tokens[0] == "rm") {
		return new RM(cmd_tokens);
	}
	else if (cmd_tokens[0] == "truncate") {
		return new Truncate(cmd_tokens);
	}
	else if (cmd_tokens[0]=="wc") {
		return new WC(cmd_tokens);
	}
	else if (cmd_tokens[0] == "date") {
		return new Date(cmd_tokens);
	}
	else if (cmd_tokens[0] == "time") {
		return new Time(cmd_tokens);
	}
	else if (cmd_tokens[0] == "prompt") {
		return new Prompt(cmd_tokens);
	}
	else if (cmd_tokens[0] == "head") {
		return new Head(cmd_tokens);
	}
	else if (cmd_tokens[0] == "tr") {
		return new TR(cmd_tokens);
	}
	else {
		throw UnknownException(cmd_tokens[0]);
	}
}
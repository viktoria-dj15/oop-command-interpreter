#include "FileCommand.h"
using namespace std;

void FileCommand::parse(vector<string> tokens) {
	if (tokens.size() > 2) throw SyntaxException("Too many arguments for file command");
	if (tokens.size() == 1) throw SyntaxException("Command: " + tokens[0]+ "requires an argument");
	if (tokens.size() == 2) {
		if (isFile(tokens[1])) {
			input = tokens[1];
		}
		else {
			throw SyntaxException("Invalid argument for file command: " + tokens[1]);
		}
	}
}
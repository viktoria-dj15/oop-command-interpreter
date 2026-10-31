#include "OutRedir.h"
#include <iostream>
using namespace std;

void OutRedir::redirection(int& i,std::vector<std::string> tokens) {
	for (i; i < tokens.size(); i++) {
		if (!isRedirection(tokens[i])) {
			throw SemanticException("Unexpected token: " + tokens[i]);
		}
		else if (tokens[i] == ">" && i + 1 < tokens.size() && output.out.empty() && isFile(tokens[i + 1])) {
			output.out = tokens[i + 1];
			output.append = false;
			i++;
		}
		else if (tokens[i] == ">>" && i + 1 < tokens.size() && output.out.empty() && isFile(tokens[i + 1])) {
			output.out = tokens[i + 1];
			output.append = true;
			i++;
		}
		else {
			if (tokens[i] == "<") {
				throw SemanticException("No input is allowed.");
			}
			if (!output.out.empty() && (tokens[i] == ">" || tokens[i] == ">>")) {
				throw SemanticException("Multiple output redirections for the same command are not allowed.");
			}
			if (i + 1 < tokens.size()) {
				throw SemanticException("Redirection operator must be followed by a file name.");
			}
			if (!isFile(tokens[i + 1]) && (tokens[i] == ">" || tokens[i] == ">>")) {
				throw SemanticException("Redirection target cannot be a quoted string.");
			}
			throw SyntaxException("Invalid redirection syntax near token: " + tokens[i]);
		}
	}
}
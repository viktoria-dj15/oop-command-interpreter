#include "InOutRedir.h"
using namespace std;	

void InOutRedir::redirect(int& i, vector<string>tokens) {
	for (i; i < tokens.size(); i++) {
		if (!isRedirection(tokens[i])) {
			throw SemanticException("Unexpected token: " + tokens[i]);
		}
		if (tokens[i] == "<" && input.empty() && i + 1 < tokens.size() && isFile(tokens[i+1])) {
			input = Reader::readFile(tokens[i + 1]);
			i++;
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
			if (!input.empty() && (tokens[i] == "<")) {
				throw SemanticException("Multiple input redirections for the same command are not allowed.");
			}
			if (!output.out.empty() && (tokens[i] == ">" || tokens[i] == ">>")) {
				throw SemanticException("Multiple output redirections for the same command are not allowed.");
			}
			if (i + 1 < tokens.size()) {
				throw SemanticException("Redirection operator must be followed by a file name.");
			}
			if (!isFile(tokens[i + 1] ) && (tokens[i] == ">" || tokens[i] == ">>" || tokens[i] == "<")) {
				throw SemanticException("Redirection target cannot be a quoted string.");
			}
			throw SyntaxException("Invalid redirection syntax near token: " + tokens[i]);
		}
	}
}

void InOutRedir::checkArgument(int& i, vector<string>tokens) {
	if (tokens.size() > i && !isRedirection(tokens[i])) {
		if (tokens[i][0] == '"' && tokens[i][tokens[i].size() - 1] == '"') {
			input = tokens[i].substr(1, tokens[i].size() - 2);
		}
		else {
			input = Reader::readFile(tokens[i]);
		}
		i++;
	}
}
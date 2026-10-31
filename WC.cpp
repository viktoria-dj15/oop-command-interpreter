#include "WC.h"
using namespace std;

void WC::parse(vector<string> tokens) {
	int i = 1;
	if (tokens[i] != "-w" && tokens[i] != "-c") throw SyntaxException("After wc must be -w or -c.");
	for (i; i < tokens.size(); i++) {
		if (tokens[i] == "-w") {
			if (w) {
				throw SemanticException("Option -w cannot appear more than once.");
			}
			w = true;
		}
		else if(tokens[i] == "-c") {
			if(c) {
				throw SemanticException("Option -c cannot appear more than once.");
			}
			c = true;
		}
		else {
			break;
		}
	}
	checkArgument(i, tokens);
	redirect(i, tokens);
}

int WC::wordCount() {
	bool startedWord = false;
	int words = 0;
	for (int i = 0; i < input.size(); i++) {
		if (isspace(input[i]) && startedWord) {
			words++;
			startedWord = false;
		}
		else {
			if (!isspace(input[i]))
				startedWord = true;
		}
	}
	if (startedWord) words++;
	return words;
}

int WC::characterCount() {
	int characters = 0;
	for (char c : input) {
		characters++;
	}
	return characters;
}

string WC::run() {
	if (input.empty()) Reader::readConsole(input);
	string num="";
	if(w) {
		num += to_string(wordCount());
	}
	if (c) {
		if (!num.empty()) num += " ";
		num += to_string(characterCount());
	}
	return num;
}
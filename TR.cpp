#include "TR.h"
using namespace std;

void TR::parse(vector<string> tokens) {
	int i = 1;
	if(tokens.size()>i&&tokens[i][0]!='-'){
		checkArgument(i, tokens);
	}
	if (tokens.size() <= i || tokens[i][0]!='-') {
		throw SyntaxException("Option string is required for tr command.");
	}
	option = tokens[i].substr(2, tokens[i].size() - 3);
	i++;
	if (i < tokens.size() && !isRedirection(tokens[i])) {
		tr_str = tokens[i].substr(1, tokens[i].size() - 2);
		i++;
	}
	redirect(i, tokens);
}

string TR::run() {
	if (input.empty()) {
		Reader::readConsole(input);
	}
	if (!tr_str.empty()) {
		replaceAll(input, option, tr_str);
	}else{
		removeAll(input, option);
	}
	return input;
}

void TR::replaceAll(string& text, const string& what, const string& with) {
	if (what.empty()) return;
	size_t pos = 0;
	while ((pos = text.find(what, pos)) != string::npos) {
		text.replace(pos, what.length(), with);
		pos += with.length(); 
	}
}


void TR::removeAll(std::string& text, const std::string& what) {
	if (what.empty()) return;
	size_t pos = 0;
	while ((pos = text.find(what, pos)) != std::string::npos) {
		text.erase(pos, what.length());
	}
}
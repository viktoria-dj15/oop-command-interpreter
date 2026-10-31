#include "Head.h"
#include <sstream>
using namespace std;

void Head::parse(std::vector<std::string> tokens) {
	int i = 1;
	string str = "";
	if (tokens.size() <= 1) {
		throw SyntaxException("Not enough arguments for head command.");
	}
	if (tokens[i].substr(0, 2) != "-n") throw SyntaxException("First argument after head must be -n.");
	if (tokens[i].size() > 7) throw SyntaxException("Too many characters in -n option.");
	for (int j = 2; j < tokens[i].size(); j++) {
		if (!isdigit(tokens[i][j])) {
			throw SyntaxException("Invalid character in -n option. Only digits are allowed.");
		}
		str += tokens[i][j];
	} 
	i++;
	for (i; i < tokens.size(); i++) {
		if (tokens[i][0] == '-') throw SyntaxException("Too many options for head command.");
	}
	n = stoi(str);
	checkArgument(i, tokens);
	redirect(i, tokens);
}

string Head::run() {
	if (input.empty()) {
		Reader::readConsole(input);
	}
	if (n >= 0) {
		ostringstream ss_res;
		istringstream ss_input(input);  
		int count = n;
		while(count > 0 && ss_input){
			string line;
			getline(ss_input, line);  
			ss_res << line;
			if (count > 1 && ss_input.peek() != EOF) ss_res << "\n";
			--count;
		}
		return ss_res.str();
	}
	return "";
}
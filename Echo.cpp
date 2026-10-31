#include "Echo.h"
#include "Reader.h"

using namespace std;

void Echo::parse(vector<string> tokens) {
	int i = 1;
	checkArgument(i, tokens);
	redirect(i, tokens);
}

string Echo::run() {
	if (input.empty()) {
	Reader::readConsole(input);
	}
	return input + "";
}
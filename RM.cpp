#include "RM.h"
#include <iostream>
using namespace std;

string RM::run() {
	if (input.empty()) {
		throw SyntaxException("rm command requires an argument");
	}
	filesystem::path filePath = input;
	if (filesystem::exists(filePath)) filesystem::remove(filePath);
	else {
		throw runtime_error("Error: File does not exist in current directory: " + input);
	}
	return "";
}
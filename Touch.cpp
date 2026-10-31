#include "Touch.h"
using namespace std;


string Touch::run() {
	if (input.empty()) {
		throw SyntaxException("Touch command requires an argument");
	}
	filesystem::path filePath =  input;
	if (filesystem::exists(filePath)) {
		throw CommandException("File already exists: " + input);
	}
	ofstream file(input); // if file does not exist, it will be created. If it exists.
	if (!file.is_open()) {
		throw runtime_error("Error opening file: " + input);
	}
	
	file.close();
	return "";

}
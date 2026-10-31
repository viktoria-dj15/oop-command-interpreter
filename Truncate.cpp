#include "Truncate.h"
#include <fstream>
using namespace std;


string Truncate::run() {
	if (input.empty()) {
		throw SyntaxException("Truncate command requires an argument");
	}
	ofstream file(input, ios::trunc);
	if (!file.is_open()) {
		throw runtime_error("Error opening file: " + input);
	}
	filesystem::path filePath =  input;
	if (!filesystem::exists(filePath)) {
		throw runtime_error("File does not exist in current diretory: " + input);
	}
	file.close();
	return "";
}
#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;

string Reader::readConsole(string& result) {
	string line;
	while (getline(cin, line)) {
		result += line;
		result += '\n';
	}
	if(cin.eof())cin.clear(); // Clear the EOF flag to allow further input if needed.
	return result;
}

string Reader::readFile(string filePath) {
	ifstream file(filePath);
	if (!file.is_open()) {
		throw runtime_error("Error opening file: " + filePath);
	}
	string line;
	string content = "";
	while (getline(file, line)) {
		content += line + "\n";
	}
	file.close();
	if (!content.empty())content.pop_back(); // Remove the last newline character
	return content;
}
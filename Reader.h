#ifndef READER_H
#define READER_H
#include <string>

// Reader class. Provides static methods to read from files and console.
class Reader{ 
public:

	static std::string readFile(std::string filePath);

	static std::string readConsole(std::string& line);
};
#endif

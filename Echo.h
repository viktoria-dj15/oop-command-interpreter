#ifndef ECHO_H
#define ECHO_H
#include "InOutRedir.h"
#include <string>
#include <vector>
#include <iostream>

// Prints the given input text to the output.
class Echo : public InOutRedir {
public:

	Echo(std::vector<std::string> tokens);

	void parse(std::vector<std::string> tokens) override;

	//	Prints the given input text.
	std::string run() override;
};


//	Inline methods definition

inline Echo::Echo(std::vector<std::string> tokens) : InOutRedir(){
	parse(tokens);
	name = "echo";
}


#endif
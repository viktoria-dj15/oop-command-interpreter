#ifndef HEAD_H
#define HEAD_H
#include "InOutRedir.h"

// Takes first n lines of the input. 
class Head : public InOutRedir {
public:

	Head(std::vector<std::string> tokens);

	// Override the run function from Command.
	std::string run() override;

	// Override the parse function from Command.
	void parse(std::vector<std::string> tokens) override;

private:
	// Number of lines to display.
	int n;
};

inline Head::Head(std::vector<std::string> tokens) : InOutRedir() {
	name = "head"; n = -1;
	parse(tokens);
}

#endif
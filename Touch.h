#ifndef TOUCH_H
#define TOUCH_H
#include "FileCommand.h"

// Touch command. Creates an empty file.
class Touch : public FileCommand{
public:

	Touch(std::vector<std::string> tokens);
	
	std::string run() override;

};

inline Touch::Touch(std::vector<std::string> tokens) : FileCommand() {
	parse(tokens);
	name = "touch";
}

#endif

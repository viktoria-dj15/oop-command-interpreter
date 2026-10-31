#ifndef TRUNCATE_H
#define TRUNCATE_H
#include "FileCommand.h"

// Truncate command. Empties the content of a file.
class Truncate : public FileCommand {
public:
	Truncate(std::vector<std::string> tokens);

	std::string run() override;

};
inline Truncate::Truncate(std::vector<std::string> tokens): FileCommand() {
	parse(tokens);
	name = "truncate";
}

#endif
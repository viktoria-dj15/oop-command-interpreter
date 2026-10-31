#ifndef RM_H
#define RM_H
#include "FileCommand.h"

// RM command. Deletes a file.
class RM : public FileCommand {
public:

	RM(std::vector<std::string> tokens);

	std::string run() override;

};

// Inline method definitions.
inline RM::RM(std::vector<std::string> tokens) : FileCommand() {
	name = "rm";
	parse(tokens);
}

#endif
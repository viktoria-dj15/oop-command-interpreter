#ifndef FILECOMMAND_H
#define FILECOMMAND_H	
#include "Command.h"
#include <fstream>
#include <filesystem>

// FileCommand class. Used for commands that take a file as an argument and have no output.
class FileCommand : public Command {
public:
	FileCommand();

	void parse(std::vector<std::string> tokens) override;
	
};
inline FileCommand::FileCommand() : Command() {}


#endif
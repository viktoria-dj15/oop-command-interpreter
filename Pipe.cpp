#include "Pipe.h"
#include <fstream>
using namespace std;

void Pipe::addCommand(Command* cmd) {
	commands.push_back(cmd);
}

void Pipe::runPipe() {
	string s="";
	Command* cmd;
	it = commands.begin();
	while (true) {
		cmd = *it;
		it++;
		if (it == commands.end()) { // last command will be executed after the loop, to handle output redirection properly.
			break;
		}
		if (!cmd->getOutput().out.empty()) {
			throw SemanticException("Output redirection is not allowed for commands in the middle of the pipe.");
		}
		if (!cmd->getInput().empty() && !s.empty()) {
			throw SemanticException("Multiple input sources for the same command are not allowed.");
		}
		if (cmd->getInput().empty()) {
			cmd->setInput(s);
		}
		s=cmd->run();
	}
	if (!cmd->getInput().empty() && !s.empty()) {
		throw SemanticException("Multiple input sources for the same command are not allowed.");
	}
	if (cmd->getInput().empty()) {
		cmd->setInput(s);
	}
	s = cmd->run();
	if (s.empty()) {
		return;
	} // If the last command produces output, we need to handle it according to the output redirection specified for that command.
	if(cmd->getOutput().out.empty()){
		*os << s; // Output to a default output stream (e.g., console or string in batch (if we have pipe in it) to be returned).
		if (cmd->getName() != "batch")
			*os << "\n";
	}
	else{
		ofstream* file;
		if (cmd->getOutput().append) {
			file = new ofstream(cmd->getOutput().out, ios::app);
		}
		else {
			file = new ofstream(cmd->getOutput().out);
		}
		if (!file->is_open()) {
			delete file;
			throw runtime_error("Error opening file: " + cmd->getOutput().out);
		}
		*file << s;
		file->close();
		delete file;
	}
	
}
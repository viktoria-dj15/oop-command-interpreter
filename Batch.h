#ifndef BATCH_H
#define BATCH_H
#include "OutRedir.h"
#include <vector>
#include <string>

// Batch command. Executes commands from a file.
class Batch: public OutRedir {
public:

	Batch(std::vector<std::string> tokens);

	std::string run() override;

	void parse(std::vector<std::string> tokens) override;

private:
	std::string argument;
};

inline Batch::Batch(std::vector<std::string> tokens) {
	name = "batch";
	parse(tokens);
}
#endif
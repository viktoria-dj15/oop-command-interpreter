#ifndef WC_H
#define WC_H
#include "InOutRedir.h"

// WC command. Counts words and characters in the input.
class WC : public InOutRedir {
public:

	WC(std::vector<std::string> tokens);

	std::string run() override;
	
	void parse(std::vector<std::string> tokens) override;

private:

	// Method for counting words in given text.
	int wordCount();

	// Method for counting characters in given text.
	int characterCount();

	// Flags to indicate whether to count words and characters.
	bool w; bool c;

};

inline WC::WC(std::vector<std::string> tokens) : InOutRedir() {
	w = false;
	c = false;
	parse(tokens);
	name = "wc";
}

#endif
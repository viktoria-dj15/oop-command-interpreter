#ifndef TR_H
#define TR_H
#include "InOutRedir.h"

// TR command. Translates characters in the input according to the specified options.
class TR : public InOutRedir {
public:

	TR(std::vector<std::string> tokens);

	void parse(std::vector<std::string> tokens) override;

	std::string run() override;

private:

	// Helper functions to perform character translation.
	void removeAll(std::string& text, const std::string& what);
	// Helper function to replace all occurrences of option characters (what) corresponding characters in tr_str (with).
	void replaceAll(std::string& text, const std::string& what, const std::string& with);

	// Option string that specifies the translation to be performed.
	std::string option;
	// String to hold the input text for translation.
	std::string tr_str;

};

inline TR::TR(std::vector<std::string> tokens) : InOutRedir() {
	name = "tr"; tr_str = ""; option = "";
	parse(tokens);
}

#endif
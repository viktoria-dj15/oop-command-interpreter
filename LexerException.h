#ifndef LEXEREXCEPTION_H
#define LEXEREXCEPTION_H
#include "Exception.h"
#include <string>
#include <iostream>
#include <vector>

// Class for Lexical errors.
class LexerException : virtual public Exception {
public:

    LexerException(std::string line,std::vector<int> pos);

protected:

	// Builds the error message with the line and the underlines the unexpected characters.
    void buildMessage();

private:
    std::string line;
	std::vector<int> badPos;
};

#endif

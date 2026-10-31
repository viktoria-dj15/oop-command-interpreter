#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "LexerException.h"

// Lexer class. Responsible for tokenizing the input command line.
class Lexer {
public:
	Lexer(std::string line);

	// Tokenizes the input line and returns a vector of tokens.
	// It throws a LexerException with the positions of the bad characters.
	std::vector<std::string> getTokens() const;

private:
	// Helper function to check if a character is allowed in a token.
	bool isAllowed(char c) const;

	// The input line to be tokenized.
	std::string line;
	
};
#endif

#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H
#include "Exception.h"
#include <string>

// SyntaxException class. Used for syntax errors in command parsing.
class SyntaxException : public Exception{
public:

    SyntaxException(std::string message);


};

inline SyntaxException::SyntaxException(std::string message) {
    this->message = message;
}
#endif
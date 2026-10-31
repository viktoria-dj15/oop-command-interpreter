#ifndef SEMANTIC_EXCEPTION_H
#define SEMANTIC_EXCEPTION_H
#include "Exception.h"

// SemanticException class. Used for semantic errors in command execution.
class SemanticException : public Exception {
public:

    SemanticException(std::string message);

};

inline SemanticException::SemanticException(std::string message) {
    this->message = message;
}
#endif
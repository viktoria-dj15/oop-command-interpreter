#ifndef UNKNOWN_H
#define UNKOWN_H
#include "Exception.h"
#include <string>

// UnknownException class. Used when an unknown command is encountered.
class UnknownException :public Exception {
public:

	UnknownException(std::string cmdName);

};

inline UnknownException::UnknownException(std::string cmdName) {
	message = "Unknown command: " + cmdName;
}
#endif

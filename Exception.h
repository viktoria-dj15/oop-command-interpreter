#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <exception>
#include <vector>
#include <iostream>
//	Generalization of all exceptions.
class Exception {
public:

	Exception() = default;

	virtual ~Exception() = default;

	// Prints the exception message.
	virtual void printMessage(std::ostream& out) const;


protected:

	std::string message;
};

//	Inline method definitions.

inline void Exception::printMessage(std::ostream& out) const {
	out << message << std::endl;
}


#endif

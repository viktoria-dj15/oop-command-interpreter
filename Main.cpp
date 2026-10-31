#include <iostream>
#include <exception>
#include "Exception.h"
#include "Interpreter.h"

using namespace std;

int main() {
	try {
		Interpreter::Instance()->process();
		Interpreter::Instance()->destroy();
	}
	catch (Exception& e) {
		e.printMessage(cerr);
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch(...) {
		cerr << "An unknown error has occured." << endl;
	}
	return 0;
}
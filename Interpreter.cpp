#include "Interpreter.h"
//#include "CommandException.h"
#include <iostream>

using namespace std;

Interpreter* Interpreter::i_instance = nullptr;

Interpreter::Interpreter() : command_prompt("$ ") {}

Interpreter* Interpreter::Instance() {
    if (!i_instance) i_instance = new Interpreter();
    return i_instance;
}

void Interpreter::destroy() {;
    delete i_instance;
    i_instance = nullptr;
}

void Interpreter::process() {
    while (true) {
        Factory* factory = nullptr;
        Pipe* p = nullptr;
        try {
            cout << command_prompt;
            string line;
            getline(cin, line);
			if (line.empty()) continue;
            factory = new Factory(line, &cout);
            p = factory->produce();
            p->runPipe();
            if (p) delete p;
            if (factory) delete factory;
        }
		catch (Exception& e) {
            if (p) delete p;
            if (factory) delete factory;
            throw e;
        }
		catch (runtime_error& e) {
            if (p) delete p;
            if (factory) delete factory;
            throw e;
        }
        
    }
}
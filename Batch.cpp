#include "Batch.h"
#include "Factory.h"
#include <fstream>
#include <sstream>
using  namespace std;


void Batch::parse(vector<string> tokens) {
	if (tokens.size() < 2||!isFile(tokens[1])) {
		throw SyntaxException("Batch command requires a file");
	}
	input = tokens[1];
	int i = 2;
	redirection(i, tokens);
}

string Batch::run() {
	if (input.empty()) {
		throw SemanticException("Batch command requires an argument");
	}
	ifstream file(input);
	if(!file.is_open()) {
		throw runtime_error("Could not open file: " + input);
	}
	string outString = "";
	stringstream* outStr=new stringstream(outString);
	string line;
	Factory* factory = nullptr;
	Pipe* p = nullptr;
	while (getline(file, line)) {
		try {
			factory = new Factory(line, outStr);
			p = factory->produce();
			p->runPipe();
			delete p;
			delete factory;
		}
		catch (Exception& e)
		{
			delete p;
			delete factory;
			e.printMessage(*outStr);
		}
		catch (runtime_error& e) {
			delete p;
			delete factory;
			*outStr << e.what() << "\n";
		}
	}
	
	
	file.close();
	outString = outStr->str();
	delete outStr;
	return outString;
}


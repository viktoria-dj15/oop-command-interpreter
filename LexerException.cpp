#include "LexerException.h"

using namespace std;

LexerException::LexerException(std::string line,vector<int> pos) : line(line), badPos(pos){
	buildMessage();
}

void LexerException::buildMessage() {
	vector<char> underline(line.size(), ' ');
	for (int pos : badPos) {
		if (pos >= 0 && pos < underline.size()) {
			underline[pos] = '^';
		}
	}
	message = "Error - unexpected characters:\n" + line + '\n' + string(underline.begin(), underline.end());
}


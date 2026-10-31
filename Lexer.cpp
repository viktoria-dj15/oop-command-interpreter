#include "Lexer.h"

using namespace std;

Lexer::Lexer(std::string line) : line(line) {
    if(line.size()>512) {
        throw LexerException(line, {});
	}
}

std::vector<std::string> Lexer::getTokens() const {
	vector<string> tokens;
	std::string cur;
    int curStart = 0;
    bool inQuotes = false;
	bool error = false;
	std::vector<int> badPos;
    for (int i = 0; i < line.size(); ++i) {
        char c = line[i];

        // Quotation marks
        if (c == '"') {
            if (!inQuotes && !cur.empty()) {
                if(cur=="-"){
                    cur.push_back(c);
                    inQuotes = !inQuotes;
                    //cur.clear();
                    continue;
                }
                cur.clear();
                error = true;
				for (int j = curStart; j < i; ++j) {
                    badPos.push_back(j);
                }   
                curStart = i;
            }
            else if (cur.empty()&&!inQuotes) {
                curStart = i;
            }
            cur.push_back(c);
            if(inQuotes) {
                tokens.push_back(cur);
                cur.clear();
			}
			inQuotes = !inQuotes;
            continue;
        }

        if (!inQuotes) {
            // white chars
            if (isspace(c)) {    
                if (!cur.empty()) {  // We have geathered entire token
                    tokens.push_back(cur);  // We are pushing it back with his start position
                    cur.clear();
                }
                continue;
            }

         
            if (c == '<' || c == '>' || c == '|') {      // Redirection and Pipe <, >, >>, |
                if (!cur.empty()) {
                    tokens.push_back(cur);
                    cur.clear();
                }

                if (c == '>' && i + 1 < line.size() && line[i + 1] == '>') {   // >>
                    tokens.push_back(">>");
                    ++i;
                }
                else {
                    tokens.push_back(string(1, c));
                }
                continue;
            }
            if (!isAllowed(c)) {       // unallowed char outsied quotation marks
				badPos.push_back(i);
                error = true;
                continue;
            }
            if (cur.empty()) curStart = i;  // i=In case we are starting new token
            cur.push_back(c);
        }
        else {
            // in quotes --> accept all
            if (cur.empty()) curStart = i;
            cur.push_back(c);
        }
    }

    if (!cur.empty()) tokens.push_back(cur);

	// open quotation marks ->error
    if (inQuotes) {
        error = true;
        for(int j = curStart; j < line.size(); ++j) {
            badPos.push_back(j);
		}
    }
    if(error) {
        throw LexerException(line, badPos);
	}
    return tokens;
}

bool Lexer::isAllowed(char c) const {
    return isalnum(c) || c == '_' || c == '-' || c == '.' || c == '/' || c == ':' || c == '\\';
}
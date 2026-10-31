#include <ctime>
#ifndef DATE_H
#define DATE_H
#include "OutRedir.h"

// Date command. Prints the current date.
class Date : public OutRedir {
public:
	Date(std::vector<std::string> tokens);

	// Prints current date.
	std::string run() override;

	void parse(std::vector<std::string> tokens) override;

private:
	//	Returns year, month, day, hours, minuts and seconds separately.
	static std::tm now();

};

inline Date::Date(std::vector<std::string> tokens) : OutRedir() {
	name = "date";
	parse(tokens);
}

inline void Date::parse(std::vector<std::string> tokens) {
	int i = 1;
	redirection(i, tokens);
}
#endif

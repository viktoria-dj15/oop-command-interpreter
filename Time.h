#include <ctime>
#ifndef TIME_H
#define TIME_H
#include "OutRedir.h"


//	Command that prints current time.
class Time : public OutRedir {
public:

	Time(std::vector<std::string> tokens);

	//	Returns year, month, day, hours, minuts and seconds separately.
	static std::tm now();

	//	Prints current time. 
	std::string run() override;
	
	void parse(std::vector<std::string> tokens) override;
};

inline Time::Time(std::vector<std::string> tokens) {
	name = "time";
	parse(tokens);
}

inline void Time::parse(std::vector<std::string> tokens) {
	int i = 1;
	redirection(i, tokens);
}



#endif

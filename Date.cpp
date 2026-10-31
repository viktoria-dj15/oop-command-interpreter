#include "Date.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;	

string Date::run() {
	std::tm t = now();

	int year = 1900 + t.tm_year;
	int month = 1 + t.tm_mon;
	int day = t.tm_mday;

	//DD.MM.YYYY
	ostringstream ss;
	ss << setfill('0')
		<< std::setw(2) << day << "."
		<< std::setw(2) << month << "."
		<< year << ".";
	return ss.str();
}

std::tm Date::now() {
	auto now = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(now);

	std::tm local{};

	localtime_s(&local, &t);

	return local;
}
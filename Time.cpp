#include "Time.h"
#include <sstream>
#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

string Time::run() {
    std::tm t = now();

    // HH:MM:SS
    ostringstream ss;
    ss << std::setfill('0')
        << std::setw(2) << t.tm_hour << ":"
        << std::setw(2) << t.tm_min << ":"
        << std::setw(2) << t.tm_sec;
    return ss.str();
}

std::tm Time::now() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm local{};

    localtime_s(&local, &t);

    return local;
}
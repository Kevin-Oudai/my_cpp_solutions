/* Codex Task: Exercise 12.25 — New Account class with Transaction log */
#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>
#include <sstream>

class Date {
public:
    Date() {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day = now->tm_mday;
    }
    Date(int year, int month, int day) : day(day), month(month), year(year) {}
    std::string toString() const {
        std::ostringstream oss;
        oss << year << '-'
            << (month < 10 ? "0" : "") << month << '-'
            << (day < 10 ? "0" : "") << day;
        return oss.str();
    }
private:
    int day;
    int month;
    int year;
};

#endif

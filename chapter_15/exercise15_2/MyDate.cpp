#include "MyDate.h"
#include <sstream>

MyDate::MyDate()
{
    year = 2026;
    month = 5;
    day = 29;
}

MyDate::MyDate(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

int MyDate::getYear() const
{
    return year;
}

int MyDate::getMonth() const
{
    return month;
}

int MyDate::getDay() const
{
    return day;
}

std::string MyDate::toString() const
{
    std::ostringstream output;
    output << month << "/" << day << "/" << year;
    return output.str();
}

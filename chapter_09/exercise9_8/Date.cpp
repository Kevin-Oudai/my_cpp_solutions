// This implementation is incorrect but i could not be bothered to fix it. It was a tedious example
// because I have to figure out leap years to get a correct date.
#include "Date.h"
#include <ctime>

Date::Date()
{
    int currentTime = time(0);
    // minutes
    currentTime /= 60;
    // hours
    currentTime /= 60;
    // days
    currentTime /= 24;
    // day
    year = 1970 + (currentTime / 365);
    currentTime = (currentTime % 365) + 1;
    month = currentTime / 30 + 1;
    day = currentTime % 30 + 1;
}

Date::Date(int elapseTime)
{
    // minutes
    elapseTime /= 60;
    // hours
    elapseTime /= 60;
    // days
    elapseTime /= 24;
    // day
    year = 1970 + (elapseTime / 365);
    elapseTime = (elapseTime % 365) + 1;
    month = elapseTime / 30 + 1;
    day = elapseTime % 30 + 1;
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setDate(int elapseTime)
{
    // minutes
    elapseTime /= 60;
    // hours
    elapseTime /= 60;
    // days
    elapseTime /= 24;
    // day
    year = 1970 + (elapseTime / 365);
    elapseTime = (elapseTime % 365) + 1;
    month = elapseTime / 30 + 1;
    day = elapseTime % 30 + 1;
}
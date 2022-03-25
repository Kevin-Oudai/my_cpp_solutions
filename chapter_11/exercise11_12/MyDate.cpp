#include "MyDate.h"
#include <ctime>

MyDate::MyDate()
{
    int currentTime = time(0);
    this->day = currentTime % (24 * 60 * 60);
    this->month = (currentTime % (365 * 24 * 60 * 60)) / 30;
    this->year = currentTime / (365 * 24 * 60 * 60);
}

MyDate::MyDate(int elapsedTime)
{
    this->day = elapsedTime % (24 * 60 * 60);
    this->month = (elapsedTime % (365 * 24 * 60 * 60)) / 30;
    this->year = elapsedTime / (365 * 24 * 60 * 60);
}

MyDate::MyDate(int year, int month, int day)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int MyDate::getYear() const
{
    return this->year;
}

int MyDate::getMonth() const
{
    return this->month;
}

int MyDate::getDay() const
{
    return this->day;
}

void MyDate::setYear(int year)
{
    this->year = year;
}

void MyDate::setMonth(int month)
{
    this->month = month;
}

void MyDate::setDay(int day)
{
    this->day = day;
}
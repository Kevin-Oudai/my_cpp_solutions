#ifndef MYDATE_H
#define MYDATE_H

#include <string>

class MyDate
{
public:
    MyDate();
    MyDate(int year, int month, int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    std::string toString() const;

private:
    int year;
    int month;
    int day;
};

#endif

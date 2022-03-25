#ifndef MYDATE_H
#define MYDATE_H

class MyDate
{
public:
    MyDate();
    MyDate(int elapsedTime);
    MyDate(int year, int month, int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

private:
    int year;
    int month;
    int day;
};
#endif
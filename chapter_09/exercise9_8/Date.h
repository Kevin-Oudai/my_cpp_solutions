#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date();
    Date(int elapsedTime);
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int elapseTime);

private:
    int year, month, day;
};
#endif
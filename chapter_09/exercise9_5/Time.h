#ifndef TIME_H
#define TIME_H

class Time
{
public:
    Time();
    Time(int secondsSince);
    Time(int h, int m, int s);
    int getHours();
    int getMinutes();
    int getSecond();
    void setTime(int elapseTime);

private:
    int hour;
    int minute;
    int second;
};
#endif
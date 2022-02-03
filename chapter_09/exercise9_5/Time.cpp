#include "Time.h"
#include <ctime>

Time::Time()
{
    second = time(0);
    minute = second / 60;
    second %= 60;
    hour = minute / 60;
    minute %= 60;
}

Time::Time(int secondsSince)
{
    minute = secondsSince / 60;
    second = secondsSince % 60;
    hour = minute / 60;
    minute %= 60;
}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

int Time::getHours()
{
    return hour;
}

int Time::getMinutes()
{
    return minute;
}

int Time::getSecond()
{
    return second;
}

void Time::setTime(int elapseTime)
{
    minute = elapseTime / 60;
    second = elapseTime % 60;
    hour = minute / 60;
    minute %= 60;
}
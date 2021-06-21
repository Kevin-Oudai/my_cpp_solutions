// Exercise 6.34 - Current date and time

#include <iostream>
#include <string>
#include <ctime>

int getCurrentSec(int &totalMilliseconds);
int getCurrentMinute(int &totalSeconds);
int getCurrentHour(int &totalMinutes);
int getCurrentYear(int &totalDays);
std::string getCurrentMonth(int &totalDays, int year);
void displayCurrentTime();

int main()
{
    displayCurrentTime();
    return 0;
}

void displayCurrentTime()
{
    int total = time(0);
    int second = getCurrentSec(total);
    int minute = getCurrentMinute(total);
    int hour = getCurrentHour(total);
    int year = getCurrentYear(total);
    std::string month = getCurrentMonth(total, year);
    int day = total;
    if (second < 10)
    {
        std::cout << "Current date and time is " << month << " " << day
                  << ", " << year << " " << hour << ":" << minute << ":0" << second << std::endl;
    }
    else
    {
        std::cout << "Current date and time is " << month << " " << day
                  << ", " << year << " " << hour << ":" << minute << ":" << second << std::endl;
    }
}

int getCurrentSec(int &totalMilliseconds)
{
    int seconds = totalMilliseconds % 60;
    totalMilliseconds /= 60;
    return seconds;
}

int getCurrentMinute(int &totalSeconds)
{
    int minutes = totalSeconds % 60;
    totalSeconds /= 60;
    return minutes;
}

int getCurrentHour(int &totalMinutes)
{
    int offset;
    std::cout << "Enter the timezone offset to GMT: ";
    std::cin >> offset;
    int hours = totalMinutes % 24;
    hours += offset;
    totalMinutes /= 24;
    hours = (hours > 12) ? hours - 12 : hours;
    return hours;
}

int getCurrentYear(int &totalDays)
{
    int year = 1969, days = 365;
    do
    {
        year++;
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        isLeapYear ? days = 366 : days = 365;
        totalDays -= days;
    } while (totalDays >= days);
    year++;
    return year;
}

std::string getCurrentMonth(int &totalDays, int year)
{
    // January
    if (totalDays > 30)
    {
        totalDays -= 30;
    }
    else
    {
        return "January";
    }

    // February
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int februaryDays = isLeapYear ? 29 : 28;
    if (totalDays > februaryDays)
    {
        totalDays -= februaryDays;
    }
    else
    {
        return "February";
    }

    // March
    if (totalDays > 31)
    {
        totalDays -= 31;
    }
    else
    {
        return "March";
    }

    // April
    if (totalDays > 30)
    {
        totalDays -= 30;
    }
    else
    {
        return "April";
    }

    // May
    if (totalDays > 31)
    {
        totalDays -= 31;
    }
    else
    {
        return "May";
    }

    // June
    if (totalDays > 30)
    {
        totalDays -= 30;
    }
    else
    {
        return "June";
    }

    // July
    if (totalDays > 31)
    {
        totalDays -= 31;
    }
    else
    {
        return "July";
    }

    // August
    if (totalDays > 31)
    {
        totalDays -= 31;
    }
    else
    {
        return "August";
    }

    // September
    if (totalDays > 30)
    {
        totalDays -= 30;
    }
    else
    {
        return "September";
    }

    // October
    if (totalDays > 31)
    {
        totalDays -= 31;
    }
    else
    {
        return "October";
    }

    // November
    if (totalDays > 30)
    {
        totalDays -= 30;
    }
    else
    {
        return "November";
    }

    // December
    return "December";
}
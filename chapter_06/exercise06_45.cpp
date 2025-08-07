// Exercise 6.45 - Current year, month, day

// Exercise 6.34 - Current date and time

#include <iostream>
#include <string>
#include <ctime>

int getCurrentYear(int &totalDays);
std::string getCurrentMonth(int &totalDays, int year);
void displayCurrentDate();

int main()
{
    displayCurrentDate();
    return 0;
}

void displayCurrentDate()
{
    int total = time(0);
    int year = getCurrentYear(total);
    std::string month = getCurrentMonth(total, year);
    int day = total;
    std::cout << "Current date is " << month << " " << day
              << ", " << year << std::endl;
}

int getCurrentYear(int &totalDays)
{
    totalDays /= 60;
    totalDays /= 60;
    totalDays /= 24;

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
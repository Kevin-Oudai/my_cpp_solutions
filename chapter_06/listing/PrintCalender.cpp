// Listing 6.19
#include <iostream>
#include <iomanip>

void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
bool isLeapYear(int year);

int main()
{
    std::cout << "Enter full year (e.g., 2001): ";
    int year;
    std::cin >> year;

    std::cout << "Enter month in number between 1 and 12: ";
    int month;
    std::cin >> month;

    printMonth(year, month);

    return 0;
}

void printMonth(int year, int month)
{
    printMonthTitle(year, month);
    printMonthBody(year, month);
}

void printMonthTitle(int year, int month)
{
    printMonthName(month);
    std::cout << " " << year << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << " Sun Mon Tue Wed Thu Fri Sat" << std::endl;
}

void printMonthName(int month)
{
    switch (month)
    {
    case 1:
        std::cout << "January";
        break;
    case 2:
        std::cout << "February";
        break;
    case 3:
        std::cout << "March";
        break;
    case 4:
        std::cout << "April";
        break;
    case 5:
        std::cout << "May";
        break;
    case 6:
        std::cout << "June";
        break;
    case 7:
        std::cout << "July";
        break;
    case 8:
        std::cout << "August";
        break;
    case 9:
        std::cout << "September";
        break;
    case 10:
        std::cout << "October";
        break;
    case 11:
        std::cout << "November";
        break;
    case 12:
        std::cout << "December";
    }
}

void printMonthBody(int year, int month)
{
    int startDay = getStartDay(year, month);
    int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);

    int i = 0;
    for (i = 0; i < startDay; i++)
    {
        std::cout << "    ";
    }
    for (i = 1; i <= numberOfDaysInMonth; i++)
    {
        std::cout << std::setw(4) << i;
        if ((i + startDay) % 7 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int getStartDay(int year, int month)
{
    int startDay1800 = 3;
    int totalNumberOfDays = getTotalNumberOfDays(year, month);

    return (totalNumberOfDays + startDay1800) % 7;
}

int getTotalNumberOfDays(int year, int month)
{
    int total = 0;

    for (int i = 1800; i < year; i++)
        if (isLeapYear(i))
            total = total + 366;
        else
            total = total + 365;

    for (int i = 1; i < month; i++)
        total = total + getNumberOfDaysInMonth(year, i);

    return total;
}

int getNumberOfDaysInMonth(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }
    return 0;
}

bool isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
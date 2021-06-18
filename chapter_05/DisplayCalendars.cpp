// Exercise 5.31 - Display Calendars

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main()
{
    std::cout << "Enter the year: ";
    int year;
    std::cin >> year;

    std::cout << "Enter the first day of the month (Sunday = 0): \n";
    int day;
    std::cin >> day;

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int daysOfMonth, offset;
    std::string monthName;

    for (int i = 1; i <= 12; i++)
    {
        switch (i)
        {
        case 1:
            daysOfMonth = 31;
            monthName = "January ";
            break;
        case 2:

            daysOfMonth = isLeapYear ? 29 : 28;
            monthName = "February ";
            break;
        case 3:
            daysOfMonth = 31;
            monthName = "March ";
            break;
        case 4:
            daysOfMonth = 30;
            monthName = "April ";
            break;
        case 5:
            daysOfMonth = 31;
            monthName = "May ";
            break;
        case 6:
            daysOfMonth = 30;
            monthName = "June ";
            break;
        case 7:
            daysOfMonth = 31;
            monthName = "July ";
            break;
        case 8:
            daysOfMonth = 31;
            monthName = "August ";
            break;
        case 9:
            daysOfMonth = 30;
            monthName = "Septemper ";
            break;
        case 10:
            daysOfMonth = 31;
            monthName = "October ";
            break;
        case 11:
            daysOfMonth = 30;
            monthName = "November ";
            break;
        case 12:
            daysOfMonth = 31;
            monthName = "December ";
            break;
        default:
            break;
        }
        offset = 24 - std::ceil((monthName.length() + 4) / 2.0);
        std::cout << std::setw(offset) << " " << monthName << year << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << " Sun    Mon    Tue    Wed    Thu    Fri    Sat \n";
        if (day != 0)
        {
            for (int j = 0; j < day; j++)
            {
                std::cout << std::setw(3) << " " << std::setw(4) << " ";
            }
        }
        for (int k = 1; k <= daysOfMonth; k++)
        {
            std::cout << std::setw(3) << k << std::setw(4) << " ";
            day++;
            if (day % 7 == 0)
            {
                std::cout << std::endl;
            }
        }
        day = day % 7;
        std::cout << "\n\n";
    }
    return 0;
}
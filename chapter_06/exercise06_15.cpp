// Exercise 6.15 - Number of days in February

#include <iostream>
#include <iomanip>

int numberOfDaysInFebruary(int year)
{
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYear)
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

int main()
{
    std::cout << std::setw(7) << std::left << "Year"
              << "February Days" << std::endl;
    for (int i = 1985; i <= 2021; i++)
    {
        std::cout << std::setw(7) << std::left << i
                  << numberOfDaysInFebruary(i) << std::endl;
    }
    return 0;
}
#include <iostream>
#include <string>

int main()
{
    std::string month;
    std::cout << "Enter a year: ";
    int year, days;
    std::cin >> year;
    std::getline(std::cin, month);
    std::cout << "Enter a month: ";
    std::getline(std::cin, month);

    // Check if it is a leap year
    bool isLeapYear = year % 4 == 0 && year % 100 == 0 && year % 400 == 0;

    // Determine the number of months for the given year
    if (month == "Sep" || month == "Apr" || month == "Jun" || month == "Nov")
    {
        days = 30;
        std::cout << month << " " << year << " has " << days << " days" << std::endl;
    }
    else if (month == "Feb")
    {
        if (isLeapYear)
        {
            days = 29;
        }
        else
            days = 30;
        std::cout << month << " " << year << " has " << days << " days" << std::endl;
    }
    else if (month == "Jan" || month == "Mar" || month == "May" || month == "Jul" || month == "Aug" || month == "Oct" || month == "Dec")
    {
        days = 31;
        std::cout << month << " " << year << " has " << days << " days" << std::endl;
    }
    else
        std::cout << month << " is not a correct month name" << std::endl;
}
// Exercise 5.30 - Display the sundays in a month
// Program assumes no leap year

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the integer of the month: ";
    int month;
    std::cin >> month;

    std::cout << "Enter the integer for the day of the week(Sunday = 0): ";
    int day;
    std::cin >> day;
    std::string dayName;

    int iLimit;
    if (
        month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11)
        iLimit = 30;
    else if (month == 2)
    {
        iLimit = 28;
    }
    else
    {
        iLimit = 31;
    }
    switch (day)
    {
    case 1:
        dayName = "Sunday";
        break;
    case 2:
        dayName = "Monday";
        break;
    case 3:
        dayName = "Tuesday";
        break;
    case 4:
        dayName = "Wednesday";
        break;
    case 5:
        dayName = "Thursday";
        break;
    case 6:
        dayName = "Friday";
        break;
    case 0:
        dayName = "Saturday";
        break;
    default:
        break;
    }
    std::cout << "The first day of the month is " << dayName << std::endl;
    for (int i = 1; i <= iLimit; i++)
    {
        if (day % 7 == 1)
        {
            std::cout << "Next Sunday of this is on " << i << ".\n";
        }
        day++;
    }
}
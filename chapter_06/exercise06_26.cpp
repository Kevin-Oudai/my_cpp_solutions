// Exercise 6.26 - Days and remaining hours
#include <iostream>
#include <string>

void getDay(int day, std::string &dayName)
{
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
    case 7:
        dayName = "Saturday";
        break;
    default:
        break;
    }
}

void getHours(int &hoursPassed)
{
    hoursPassed = 24 - hoursPassed;
}

int main()
{
    int day, hoursPassed;
    std::string dayName;
    std::cout << "Enter the day number: ";
    std::cin >> day;
    std::cout << "Enter the hours passed: ";
    std::cin >> hoursPassed;
    getHours(hoursPassed);
    getDay(day, dayName);
    std::cout << "Today is " << dayName << std::endl;
    std::cout << "Remaining Hours: " << hoursPassed << std::endl;
    return 0;
}
#include <iostream>
#include <string>

int main()
{
    int day, hoursPassed;
    std::string dayName;
    std::cout << "Enter the day number: ";
    std::cin >> day;
    std::cout << "Enter the hours passed: ";
    std::cin >> hoursPassed;

    hoursPassed = 24 - hoursPassed;
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

    std::cout << "Today is " << dayName << std::endl;
    std::cout << "Remaining Hours: " << hoursPassed << std::endl;
    return 0;
}
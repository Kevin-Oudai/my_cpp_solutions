#include <iostream>
#include <string>

int main()
{
    int dayOfTheWeek, dayOfTheMonth, month, century, yearOfTheCentury;
    std::string dayName;
    std::cout << "Enter year: (e.g., 2012): ";
    std::cin >> yearOfTheCentury;

    std::cout << "Enter month: 1 - 12: ";
    std::cin >> month;

    std::cout << "Enter the day of the month: 1 - 31: ";
    std::cin >> dayOfTheMonth;

    if (month == 1 || month == 2)
    {
        month += 12;
        yearOfTheCentury -= 1;
    }
    century = yearOfTheCentury / 100;
    yearOfTheCentury %= 100;

    month = (26 * (month + 1)) / 10;
    dayOfTheWeek = (dayOfTheMonth + month + yearOfTheCentury + yearOfTheCentury / 4 +
                    century / 4 + century * 5) %
                   7;

    switch (dayOfTheWeek)
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

    std::cout << "Day of the week is " << dayName << std::endl;

    return 0;
}
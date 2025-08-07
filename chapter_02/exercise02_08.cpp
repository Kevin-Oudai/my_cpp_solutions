// Revised listing 2.9 - ShowCurrentTime.cpp
#include <iostream>
#include <ctime>

int main()
{
    // Obtain the total seconds since the midnight, Jan 1, 1970
    int totalSeconds = time(0);
    int offset;
    std::cout << "Enter the timezone offset to GMT: ";
    std::cin >> offset;

    // Compute the current second in the minute in the hour
    int currentSecond = totalSeconds % 60;

    // Obtain the total minutes
    int totalMinutes = totalSeconds / 60;

    // Compute the current minute in the hour
    int currentMinute = totalMinutes % 60;

    // Obtain the total hours
    int totalHours = totalMinutes / 60;
    totalHours += offset;
    // Compute the current hour
    int currentHour = totalHours % 24;

    // Display  results
    std::cout << "Current time is " << currentHour << ":"
              << currentMinute << ":" << currentSecond << " GMT" << std::endl;

    return 0;
}
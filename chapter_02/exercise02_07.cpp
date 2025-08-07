#include <iostream>

int main()
{
    int numberOfMinutes, numberOfYears, numberOfDays;
    std::cout << "Enter the number of minutes: ";
    std::cin >> numberOfMinutes;
    numberOfDays = numberOfMinutes / (60.0 * 24);
    numberOfYears = numberOfDays / 365;
    numberOfDays %= 365;
    std::cout << numberOfMinutes << " minutes is approximately "
              << numberOfYears << " years and "
              << numberOfDays << " days." << std::endl;
    return 0;
}
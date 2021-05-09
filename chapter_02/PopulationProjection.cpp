#include <iostream>
#include <iomanip>

int main()
{
    double initialPopulation = 312032486;
    double birthPerSecond = 1.0 / 7;
    double deathPerSecond = 1.0 / 13;
    double immigrantPerSecond = 1.0 / 45;
    double populationChange = birthPerSecond + immigrantPerSecond - deathPerSecond;
    double secondsPerDay = 24.0 * 60 * 60;
    double days = 365;
    int numberOfYears;
    std::cout << "Enter the number of years: ";
    std::cin >> numberOfYears;
    std::cout << std::setprecision(0) << std::showpoint << std::fixed;
    std::cout << "At the start of the first year the population is: " << initialPopulation
              << std::endl;
    std::cout << "At the end of the first year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay * numberOfYears << "." << std::endl;
    return 0;
}
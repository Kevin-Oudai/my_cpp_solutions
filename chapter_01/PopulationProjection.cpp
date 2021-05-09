#include <iostream>

int main()
{
    double initialPopulation = 312032486;
    double birthPerSecond = 1.0 / 7;
    double deathPerSecond = 1.0 / 13;
    double immigrantPerSecond = 1.0 / 45;
    double populationChange = birthPerSecond + immigrantPerSecond - deathPerSecond;
    double secondsPerDay = 24.0 * 60 * 60;
    double days = 365;
    std::cout << "At the start of the first year the population is: " << initialPopulation
              << std::endl;
    std::cout << "At the end of the first year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay << "." << std::endl;
    std::cout << "At the end of the second year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay * 2 << "." << std::endl;
    std::cout << "At the end of the third year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay * 3 << "." << std::endl;
    std::cout << "At the end of the fourth year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay * 4 << "." << std::endl;
    std::cout << "At the end of the fifth year the population is: "
              << initialPopulation + 365 * populationChange * secondsPerDay * 5 << "." << std::endl;
    return 0;
}
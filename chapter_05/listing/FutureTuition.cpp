// Listing 5.1 - FutureTuition.cpp

#include <iostream>
#include <iomanip>

int main()
{
    double tuition = 10000;
    int year = 1;
    while (tuition < 20000)
    {
        tuition = tuition * 1.07;
        year++;
    }
    std::cout << "Tuition will be doubled in " << year << " years" << std::endl;
    std::cout << std::setprecision(2) << std::fixed << std::showpoint
              << "Tuition will be $" << tuition << " in " << year << " years" << std::endl;

    return 0;
}
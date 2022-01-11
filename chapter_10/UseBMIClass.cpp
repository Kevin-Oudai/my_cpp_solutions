#include <iostream>
#include "BMI.h"

int main()
{
    BMI bmi1("John Doe", 18, 145, 70);
    std::cout << "The BMI for " << bmi1.getName() << " is "
              << bmi1.getBMI() << " " << bmi1.getStatus() << std::endl;

    BMI bmi2("Susan King", 215, 70);
    std::cout << "The BMI for " << bmi2.getName() << " is "
              << bmi2.getBMI() << " " + bmi2.getStatus() << std::endl;

    return 0;
}
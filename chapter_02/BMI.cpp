#include <iostream>
#include <cmath>

int main()
{
    double weightInKilograms, weightInPounds, heightInMetres, heightInInches, bmi;
    double POUND_TO_KILOGRAM = 0.45359237;
    double INCH_TO_METRE = 0.0254;

    std::cout << "Enter weight in pounds: ";
    std::cin >> weightInPounds;
    std::cout << "Enter height in inches: ";
    std::cin >> heightInInches;

    weightInKilograms = weightInPounds * POUND_TO_KILOGRAM;
    heightInMetres = heightInInches * INCH_TO_METRE;

    bmi = weightInKilograms / pow(heightInMetres, 2);

    std::cout << "BMI is " << bmi << std::endl;
    return 0;
}
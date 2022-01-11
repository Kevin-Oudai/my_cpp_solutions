#include <iostream>
#include "BMI.h"

BMI::BMI(const std::string &newName, int newAge, double newWeight, double newHeight)
{
    name = newName;
    age = newAge;
    weight = newWeight;
    height = newHeight;
}

BMI::BMI(const std::string &newName, double newWeight, double newHeight)
{
    name = newName;
    age = 20;
    weight = newWeight;
    height = newHeight;
}

double BMI::getBMI() const
{
    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;
    double bmi = weight * KILOGRAMS_PER_POUND / ((height * METERS_PER_INCH) * (height * METERS_PER_INCH));
    return bmi;
}

std::string BMI::getStatus() const
{
    double bmi = getBMI();
    if (bmi < 18.5)
        return "Underweight";
    else if (bmi < 25)
        return "Normal";
    else if (bmi < 30)
        return "Overweight";
    else
        return "Obese";
}

std::string BMI::getName() const
{
    return name;
}

int BMI::getAge() const
{
    return age;
}

double BMI::getWeight() const
{
    return weight;
}

double BMI::getHeight() const
{
    return height;
}
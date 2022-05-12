// Exercise 6.19 - Reverse Armstrong number
#include <iostream>
#include <cmath>

int cubeOfDigits(int number)
{
    double sum = 0;
    int count = 0;
    while (number > 0)
    {
        sum += (std::pow((number % 10), 3));
        number /= 10;
    }
    return sum;
}

void isArmstrong(int sum, int number)
{
    sum == number ? std::cout << number << " is an Armstrong integer.\n" : std::cout << number << " is NOT an Armstrong integer.\n";
}

int reverseInteger(int number)
{
    int newInteger = 0;
    while (number > 0)
    {
        newInteger = (newInteger * 10) + (number % 10);
        number /= 10;
    }
    return newInteger;
}

int main()
{
    // Test cubeOfDigits function
    // (cubeOfDigits(131) == 29) ? std::cout << "Cube of Digits function works\n" : std::cout << "cubeOfDigits function does NOT work\n";

    // Test Armstrong Integer
    std::cout << "Enter an integer: ";
    int number, sum;
    std::cin >> number;

    sum = cubeOfDigits(number);
    std::cout << "Forward: " << std::endl;
    isArmstrong(sum, number);
    int rev = reverseInteger(number);
    std::cout << "Reverse: " << std::endl;
    isArmstrong(sum, rev);

    return 0;
}
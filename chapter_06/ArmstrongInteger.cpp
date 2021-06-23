// Exercise 6.3 - Armstrong Integer

#include <iostream>
#include <cmath>

// Return the sum of the cubes of the digits in an integer,
// i.e., cubeOfDigits(131) returns 1^3 + 3^3 + 1^3 = 29
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

// Display if integer is an Armstrong integer
void isArmstrong(int sum, int number)
{
    sum == number ? std::cout << number << " is an Armstrong integer.\n" : std::cout << number << " is NOT an Armstrong integer.\n";
}

int main()
{
    // Test cubeOfDigits function
    (cubeOfDigits(131) == 29) ? std::cout << "Cube of Digits function works\n" : std::cout << "cubeOfDigits function does NOT work\n";

    // Test Armstrong Integer
    std::cout << "Enter an integer: ";
    int number, sum;
    std::cin >> number;

    sum = cubeOfDigits(number);
    isArmstrong(sum, number);
    return 0;
}
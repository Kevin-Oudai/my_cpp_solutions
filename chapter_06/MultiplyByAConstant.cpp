// Exercise 6.31 - Multiply by a constant value

#include <iostream>

void multiply(double &num1, double &num2, double &num3, int constant)
{
    num1 *= constant;
    num2 *= constant;
    num3 *= constant;
}

int main()
{
    std::cout << "Enter 3 numbers: ";
    double num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;

    std::cout << "Enter a constant: ";
    int number;
    std::cin >> number;

    multiply(num1, num2, num3, number);
    std::cout << num1 << " " << num2 << " " << num3 << std::endl;
    return 0;
}
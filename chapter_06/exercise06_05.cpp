// Exercise 6.5 - Largest of three numbers

#include <iostream>

double max(double num1, double num2)
{
    double result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

void displayLargest(double num1, double num2, double num3)
{
    double largest = max(num1, num2);
    largest = max(largest, num3);
    std::cout << "The largest of " << num1 << ", " << num2 << ", and " << num3 << " is " << largest << ".\n";
}

int main()
{
    std::cout << "Enter three numbers: ";
    double num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;
    displayLargest(num1, num2, num3);
    return 0;
}
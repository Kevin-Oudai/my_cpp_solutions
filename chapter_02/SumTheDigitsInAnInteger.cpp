#include <iostream>

int main()
{
    int number, extractedDigit;
    int total = 0;
    std::cout << "Enter a number between 0 and 1000: ";
    std::cin >> number;
    extractedDigit = number % 10;
    total += extractedDigit;
    number /= 10;
    extractedDigit = number % 10;
    total += extractedDigit;
    number /= 10;
    extractedDigit = number % 10;
    total += extractedDigit;
    std::cout << "The sum of the digits is " << total << std::endl;
    return 0;
}
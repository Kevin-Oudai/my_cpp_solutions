// Exercise 5.18 - First five multiples of an integer

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;
    int count = 1;
    while (count <= 5)
    {
        std::cout << number * count;
        (count == 5) ? std::cout << ".\n" : std::cout << ", ";
        count++;
    }
    return 0;
}
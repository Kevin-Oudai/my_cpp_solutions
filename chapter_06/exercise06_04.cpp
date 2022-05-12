// Exercise 6.4 - Display even digits in an integer

#include <iostream>

void displayEven(int number)
{
    int digit = 0;
    while (number > 0)
    {
        digit = number % 10;
        if (digit % 2 == 0)
        {
            std::cout << digit << " ";
        }
        number /= 10;
    }
}

int main()
{
    std::cout << "Enter and integer: ";
    int number;
    std::cin >> number;
    displayEven(number);
    return 0;
}
// Exercise 6.28 - Even or Odd digit integer

#include <iostream>

int getType(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int main()
{
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    if (getType(number) % 2 == 0)
    {
        std::cout << number << " is an even digit integer." << std::endl;
    }
    else
    {
        std::cout << number << " is an odd digit integer." << std::endl;
    }

    return 0;
}
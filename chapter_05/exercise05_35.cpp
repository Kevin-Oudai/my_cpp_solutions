// Exercise 5.35 - FibonacciSeries

#include <iostream>

int main()
{
    int first = 0, second = 1, temp = 0;
    std::cout << first << " " << second << " ";
    for (int i = 2; i < 10; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
        std::cout << second << " ";
    }
    std::cout << std::endl;
    return 0;
}
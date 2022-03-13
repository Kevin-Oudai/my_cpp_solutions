#include <iostream>
#include "StackOfIntegers.h"

int main()
{
    std::cout << "Enter an integer: ";
    int value;
    std::cin >> value;
    StackOfIntegers multiplesStack;
    for (int i = 1; i <= 10; i++)
    {
        multiplesStack.push(value * i);
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << multiplesStack.pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}
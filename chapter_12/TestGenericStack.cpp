#include <iostream>
#include <string>
#include "GenericStack.h"

int main()
{
    // Create a stack of int values
    Stack<int> intStack;
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }
    while (!intStack.empty())
    {
        std::cout << intStack.pop() << " ";
    }
    std::cout << std::endl;

    // Create a stack of string
    Stack<std::string> stringStack;
    stringStack.push("Chicago");
    stringStack.push("Denver");
    stringStack.push("London");

    while (!stringStack.empty())
    {
        std::cout << stringStack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
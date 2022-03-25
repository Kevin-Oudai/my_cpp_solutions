#include <iostream>
#include <string>
#include "GenericStack.h"

template <typename T>
void printStack(Stack<T> &stack)
{
    while (!stack.empty())
    {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Create a stack of int values
    Stack<int> intStack;
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }
    printStack(intStack);

    // Create a stack of string
    Stack<std::string> stringStack;
    stringStack.push("Chicago");
    stringStack.push("Denver");
    stringStack.push("London");
    printStack(stringStack);

    return 0;
}
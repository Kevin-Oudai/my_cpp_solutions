#include <iostream>
#include "StackOfIntegers.h"

void printStack(const StackOfIntegers &stack)
{
    for (int i = 0; i < stack.getSize(); i++)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    StackOfIntegers stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    std::cout << "Original stack values: ";
    printStack(stack);

    stack[1] = 200;
    stack[3] = 400;

    std::cout << "After using the [] operator: ";
    printStack(stack);

    return 0;
}

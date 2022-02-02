#include <iostream>
#include "StackOfIntegers.h"

int main()
{
    StackOfIntegers stack;
    for (int i = 0; i < 10; i++)
        stack.push(i);
    while (!stack.isEmpty())
        std::cout << stack.pop() << " ";

    return 0;
}
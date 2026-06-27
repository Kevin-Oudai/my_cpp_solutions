#include "EmptyStackException.h"
#include "StackOfIntegers.h"
#include <iostream>

int main()
{
    StackOfIntegers stack;

    try
    {
        stack.push(10);
        stack.push(20);

        std::cout << "Top value: " << stack.peek() << std::endl;
        int firstValue = stack.pop();
        std::cout << "Popped value: " << firstValue << std::endl;
        int secondValue = stack.pop();
        std::cout << "Popped value: " << secondValue << std::endl;
        int thirdValue = stack.pop();
        std::cout << "Popped value: " << thirdValue << std::endl;
    }
    catch (const EmptyStackException &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

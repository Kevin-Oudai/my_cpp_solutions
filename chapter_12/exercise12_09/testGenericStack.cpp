#include <iostream>
#include "GenericStack.h"

int main()
{
    Stack<int> numbers;
    numbers.push(5);
    numbers.push(2);
    numbers.push(3);
    numbers.push(6);
    numbers.push(8);
    numbers.push(5);
    numbers.push(2);
    numbers.printStack();
    return 0;
}
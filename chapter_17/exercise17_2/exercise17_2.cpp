#include <iostream>
#include "FibonacciCalculator.h"

int main()
{
    int index;
    std::cout << "Enter an index for the Fibonacci number: ";
    std::cin >> index;

    FibonacciCalculator calculator;
    std::cout << "Fibonacci number at index " << index
              << " is " << calculator.fib(index) << std::endl;

    return 0;
}

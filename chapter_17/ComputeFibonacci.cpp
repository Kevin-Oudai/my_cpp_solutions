#include <iostream>

// The function for finding the Fibonacci number
int fib(int);

int main()
{
    // Prompt the user to enter an integer
    std::cout << "Enter an index for the Fibonacci number: ";
    int index;

    std::cin >> index;

    // Display factorial
    std::cout << "Fibonacci number at index " << index << " is " << fib(index) << std::endl;

    return 0;
}

// The function for finding the Fibonacci number
int fib(int index)
{
    if (index == 0) // base case
    {
        return 0;
    }
    else if (index == 1) // base case
    {
        return 1;
    }
    else // Reduction and recursive calls
        return fib(index - 1) + fib(index - 2);
}
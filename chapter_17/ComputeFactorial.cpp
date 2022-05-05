#include <iostream>

unsigned factorial(unsigned);

int main()
{
    std::cout << "Please enter a non-negative integer: ";
    unsigned n;
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n);

    return 0;
}

unsigned factorial(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return n * factorial(n - 1);
}
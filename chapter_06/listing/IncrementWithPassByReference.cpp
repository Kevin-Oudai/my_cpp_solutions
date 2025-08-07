// Listing 6.16

#include <iostream>

void increment(int &n)
{
    n++;
    std::cout << "n inside the function is " << n << std::endl;
}

int main()
{
    int x = 1;
    std::cout << "Before the call, x is " << x << std::endl;
    increment(x);
    std::cout << "After the call, x is " << x << std::endl;

    return 0;
}
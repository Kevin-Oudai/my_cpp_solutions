// Listing 6.1 - TestMax.cpp
#include <iostream>

// Return the max between two numbers
int max(int num1, int num2)
{
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

int main()
{
    int i = 5;
    int j = 2;
    int k = max(i, j);
    std::cout << "The maximum between " << i << " and "
              << j << " is " << k << std::endl;

    return 0;
}
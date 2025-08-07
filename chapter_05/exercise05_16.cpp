// Exercise 5.16 - Compute the greatest common divisor

#include <iostream>

int main()
{
    int n1, n2, min;
    std::cout << "Enter the values of n1 and n2: ";
    std::cin >> n1 >> n2;
    min = n1;
    if (n1 > n2)
    {
        min = n2;
    }

    while (true)
    {
        if (n1 % min == 0 && n2 % min == 0)
        {
            break;
        }
        min--;
    }
    std::cout << "The GCD of " << n1 << " and " << n2 << " is " << min << std::endl;
    return 0;
}
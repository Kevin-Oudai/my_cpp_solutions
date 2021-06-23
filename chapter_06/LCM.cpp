// Exercise 6.18 - Modify the gcd function

#include <iostream>

int lcm(int n1, int n2)
{
    int lcm;
    n1 > n2 ? lcm = n1 : lcm = n2;

    while (lcm <= n1 * n2)
    {
        if (lcm % n1 == 0 && lcm % n2 == 0)
        {
            return lcm;
        }
        lcm++;
    }
    return n1 * n2;
}

int main()
{
    if (lcm(25, 75) == 75 && lcm(12, 18) == 36)
        std::cout << "The LCM Function works" << std::endl;
    else
    {
        std::cout << "The function returned " << lcm(25, 75) << " and " << lcm(12, 18) << std::endl;
    }

    return 0;
}
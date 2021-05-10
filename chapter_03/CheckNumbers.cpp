#include <iostream>

int main()
{
    int n1, n2;
    std::cout << "Enter two integers: ";
    std::cin >> n1 >> n2;

    if (n1 % n2 == 0)
    {
        std::cout << n1 << " is divisible by " << n2 << std::endl;
    }
    else
        std::cout << n1 << " is not divisible by " << n2 << std::endl;

    return 0;
}
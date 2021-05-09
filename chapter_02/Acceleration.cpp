#include <iostream>

int main()
{
    double v0, v1, t, a;
    std::cout << "Enter v0, v1, and t: ";
    std::cin >> v0 >> v1 >> t;
    a = (v1 - v0) / t;
    std::cout << "The average acceleration is " << a << std::endl;
    return 0;
}
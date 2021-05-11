#include <iostream>

int main()
{
    int n1, n2, n3;
    std::cout << "Enter 3 integers: ";
    std::cin >> n1 >> n2 >> n3;

    if (n1 == n2 && n2 == n3)
        std::cout << "Equilateral Triangle" << std::endl;
    else if (n1 == n2 || n2 == n3 || n3 == n1)
    {
        std::cout << "Isosceles Triangle" << std::endl;
    }
    else
        std::cout << "Scalene Triangle" << std::endl;

    return 0;
}
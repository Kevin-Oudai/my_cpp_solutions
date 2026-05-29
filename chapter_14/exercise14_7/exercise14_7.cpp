#include <iomanip>
#include <iostream>
#include "Complex.h"

int main()
{
    Complex first;
    Complex second;

    std::cout << "Enter the first complex number: ";
    std::cin >> first;

    std::cout << "Enter the second complex number: ";
    std::cin >> second;

    std::cout << "(" << first << ") + (" << second << ") = " << first + second << std::endl;
    std::cout << "(" << first << ") - (" << second << ") = " << first - second << std::endl;
    std::cout << "(" << first << ") * (" << second << ") = " << first * second << std::endl;
    std::cout << "(" << first << ") / (" << second << ") = " << first / second << std::endl;

    std::cout << std::setprecision(16);
    std::cout << "|" << first << "| = " << first.abs() << std::endl;

    return 0;
}

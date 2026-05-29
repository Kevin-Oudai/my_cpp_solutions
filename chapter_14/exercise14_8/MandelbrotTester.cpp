#include "MandelbrotTester.h"
#include <iostream>

MandelbrotTester::MandelbrotTester(int maximumIterations)
{
    this->maximumIterations = maximumIterations;
}

bool MandelbrotTester::isInSet(const Complex &c) const
{
    Complex z;
    for (int i = 0; i < maximumIterations; i++)
    {
        z = z * z + c;
        if (z.abs() > 2)
        {
            return false;
        }
    }
    return true;
}

void MandelbrotTester::run() const
{
    Complex c;
    std::cout << "Enter a complex number c: ";
    std::cin >> c;

    if (isInSet(c))
    {
        std::cout << c << " is in the Mandelbrot set" << std::endl;
    }
    else
    {
        std::cout << c << " is not in the Mandelbrot set" << std::endl;
    }
}

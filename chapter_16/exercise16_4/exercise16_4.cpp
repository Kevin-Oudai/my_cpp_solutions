#include "Rational.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Rational rational(4, 6);

    try
    {
        std::cout << "Rational number: " << rational << std::endl;
        std::cout << "rational[0]: " << rational[0] << std::endl;
        std::cout << "rational[1]: " << rational[1] << std::endl;
        long long invalidValue = rational[2];
        std::cout << "rational[2]: " << invalidValue << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

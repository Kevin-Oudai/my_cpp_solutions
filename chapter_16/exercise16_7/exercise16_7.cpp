#include "IllegalSubscriptException.h"
#include "Rational.h"
#include <iostream>

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
    catch (const IllegalSubscriptException &ex)
    {
        std::cout << ex.what() << ": " << ex.getIndex() << std::endl;
    }

    return 0;
}

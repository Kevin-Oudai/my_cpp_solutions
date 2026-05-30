#include <iostream>
#include "DigitProduct.h"

int main()
{
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    DigitProduct product;
    std::cout << "The product of digits is " << product.productDigits(n) << std::endl;

    return 0;
}

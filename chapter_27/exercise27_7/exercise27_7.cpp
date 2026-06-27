#include "../HashUtilities.h"
#include <iomanip>
#include <iostream>

int main()
{
    double value = 3.5;
    long long bits = doubleToLongLongBits(value);

    std::cout << "doubleToLongLongBits(3.5): 0x" << std::hex << bits << std::dec << std::endl;

    return 0;
}

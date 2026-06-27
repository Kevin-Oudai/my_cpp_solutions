#include "../HashUtilities.h"
#include <iomanip>
#include <iostream>

int main()
{
    float value = 3.5f;
    int bits = floatToIntBits(value);

    std::cout << "floatToIntBits(3.5): 0x" << std::hex << bits << std::dec << std::endl;

    return 0;
}

#include "../HashUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string value = "hashing";
    std::cout << "Hash code for hashing: " << hashCodeForString(value) << std::endl;

    return 0;
}

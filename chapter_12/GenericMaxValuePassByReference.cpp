#include <iostream>
#include <string>

template <typename T>
T maxValue(const T &value1, const T &value2)
{
    if (value1 > value2)
    {
        return value1;
    }
    else
    {
        return value2;
    }
}

int main()
{
    std::cout << "Maximum between 1 and 3 is " << maxValue(1, 3) << std::endl;
    std::cout << "Maximum between 1.5 and 0.3 is " << maxValue(1.5, 0.3) << std::endl;
    std::cout << "Maximum between 'A' and 'N' is " << maxValue('A', 'N') << std::endl;
    std::cout << "Maximum between \"NBC\" and \"ABC\" is " << maxValue(std::string("NBC"), std::string("ABC")) << std::endl;
    return 0;
}
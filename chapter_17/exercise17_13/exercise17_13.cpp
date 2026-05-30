#include <iostream>
#include <vector>
#include "SmallestFinder.h"

int main()
{
    std::vector<int> values(5);
    std::cout << "Enter five integers: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> values[i];
    }

    SmallestFinder finder;
    std::cout << "The smallest integer is " << finder.smallest(values) << std::endl;

    return 0;
}

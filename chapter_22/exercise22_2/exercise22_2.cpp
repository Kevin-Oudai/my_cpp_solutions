#include "../ContainerUtilities.h"
#include <iostream>
#include <list>

int main()
{
    std::list<int> numbers;
    numbers.push_back(4);
    numbers.push_back(8);
    numbers.push_back(15);
    numbers.push_back(16);
    numbers.push_back(23);
    numbers.push_back(42);

    std::cout << "Position of 16: " << exercise22::find<int>(numbers, 16) << std::endl;
    std::cout << "Position of 99: " << exercise22::find<int>(numbers, 99) << std::endl;

    return 0;
}

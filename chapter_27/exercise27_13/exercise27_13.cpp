#include "../HashUtilities.h"
#include <iostream>

int main()
{
    MySet<int> set;
    set.add(3);
    set.add(1);
    set.add(2);

    std::cout << "Set values: ";
    for (MySet<int>::Iterator iterator = set.begin(); iterator != set.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;

    return 0;
}

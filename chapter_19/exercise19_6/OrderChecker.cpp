#include "OrderChecker.h"
#include <iostream>

void OrderChecker::run() const
{
    int ascendingList[] = {1, 2, 3, 4, 5};
    int descendingList[] = {5, 4, 3, 2, 1};
    int unorderedList[] = {1, 3, 2, 5, 4};

    std::cout << std::boolalpha;
    std::cout << "ascendingList ordered ascending: "
              << ordered(ascendingList, 5) << std::endl;
    std::cout << "descendingList ordered ascending: "
              << ordered(descendingList, 5) << std::endl;
    std::cout << "descendingList ordered descending: "
              << ordered(descendingList, 5, false) << std::endl;
    std::cout << "unorderedList ordered ascending: "
              << ordered(unorderedList, 5) << std::endl;
}

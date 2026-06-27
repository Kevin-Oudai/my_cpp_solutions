#include "../HashUtilities.h"
#include <iostream>

int main()
{
    MyMultiSet<int> set;
    set.add(4);
    set.add(4);
    set.add(7);

    std::cout << "Multiset size: " << set.getSize() << std::endl;
    std::cout << "Occurrences of 4: " << set.count(4) << std::endl;

    return 0;
}

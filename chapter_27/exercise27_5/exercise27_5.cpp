#include "../HashUtilities.h"
#include <iostream>

int main()
{
    MySet<int> set;
    set.add(10);
    set.add(20);
    set.add(10);

    std::cout << "Set size: " << set.getSize() << std::endl;
    std::cout << "Contains 20: " << (set.contains(20) ? "true" : "false") << std::endl;

    return 0;
}

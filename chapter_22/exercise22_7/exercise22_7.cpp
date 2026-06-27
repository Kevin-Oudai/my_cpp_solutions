#include "../ContainerUtilities.h"
#include <iostream>
#include <set>

int main()
{
    std::set<int> s1;
    std::set<int> s2;
    std::set<int> s3;

    s1.insert(1);
    s1.insert(3);
    s1.insert(5);
    s2.insert(3);
    s2.insert(4);
    s2.insert(6);

    exercise22::setUnion<int>(s1, s2, s3);

    std::cout << "Union: ";
    exercise22::printContainer(s3);

    return 0;
}

#include "../ContainerUtilities.h"
#include <iostream>
#include <set>

int main()
{
    std::set<int> s1;
    std::set<int> s2;
    std::set<int> s3;

    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s2.insert(2);
    s2.insert(4);

    exercise22::difference<int>(s1, s2, s3);

    std::cout << "Difference: ";
    exercise22::printContainer(s3);

    return 0;
}

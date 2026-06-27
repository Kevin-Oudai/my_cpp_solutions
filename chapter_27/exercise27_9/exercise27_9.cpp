#include "../HashUtilities.h"
#include <iostream>
#include <set>
#include <string>

int main()
{
    MyHashMap<int, std::string> map;
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");

    std::set<int> keys = map.getKeys();
    std::cout << "Keys: ";
    for (std::set<int>::iterator iterator = keys.begin(); iterator != keys.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;

    return 0;
}

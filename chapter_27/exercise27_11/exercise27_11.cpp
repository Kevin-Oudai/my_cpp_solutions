#include "../HashUtilities.h"
#include <iostream>
#include <string>

int main()
{
    MyHashMap<int, std::string> map;
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");

    std::cout << "Entries: ";
    for (MyHashMap<int, std::string>::Iterator iterator = map.begin(); iterator != map.end(); iterator++)
    {
        std::pair<int, std::string> entry = *iterator;
        std::cout << "(" << entry.first << ", " << entry.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}

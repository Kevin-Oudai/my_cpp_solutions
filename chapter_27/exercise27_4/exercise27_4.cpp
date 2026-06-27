#include "../HashUtilities.h"
#include <iostream>
#include <set>
#include <string>

int main()
{
    DuplicateKeyMap<int, std::string> map;
    map.put(1, "red");
    map.put(1, "green");
    map.put(2, "blue");
    map.put(1, "red");

    std::set<std::string> values = map.getAll(1);
    std::cout << "Values for key 1: ";
    for (std::set<std::string>::iterator iterator = values.begin(); iterator != values.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;

    return 0;
}

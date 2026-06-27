#include "../HashUtilities.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    MyHashMap<int, std::string> map;
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");

    std::vector<std::string> values = map.getValues();
    std::cout << "Values: ";
    for (int i = 0; i < static_cast<int>(values.size()); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;

    return 0;
}

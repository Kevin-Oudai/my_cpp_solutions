#include "../HashUtilities.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    MyMultiMap<int, std::string> map;
    map.put(1, "red");
    map.put(1, "green");
    map.put(2, "blue");

    std::vector<std::string> values = map.getAll(1);
    std::cout << "Values for key 1: ";
    for (int i = 0; i < static_cast<int>(values.size()); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;

    return 0;
}

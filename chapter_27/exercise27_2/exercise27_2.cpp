#include "../HashUtilities.h"
#include <iostream>
#include <string>

int main()
{
    QuadraticProbingMap<std::string> map;
    map.put(1, "one");
    map.put(5, "five");
    map.put(9, "nine");

    std::string value;
    map.get(9, value);
    std::cout << "Value for key 9: " << value << std::endl;
    std::cout << "Table size: " << map.getTableSize() << std::endl;
    map.printEntries();

    return 0;
}

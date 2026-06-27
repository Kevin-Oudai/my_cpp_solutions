#include "../LinkedList.h"
#include <iostream>
#include <string>

int main()
{
    LinkedList<std::string> list;
    list.add("Beijing");
    list.add("Tokyo");
    list.add("Paris");
    list.add("London");
    list.add("Paris");

    std::cout << "First Paris index: " << list.indexOf("Paris") << std::endl;
    std::cout << "Last Paris index: " << list.lastIndexOf("Paris") << std::endl;
    std::cout << "Last Rome index: " << list.lastIndexOf("Rome") << std::endl;

    return 0;
}

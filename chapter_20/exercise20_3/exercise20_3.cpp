#include "../LinkedList.h"
#include <iostream>
#include <string>

int main()
{
    LinkedList<std::string> list;
    list.add("America");
    list.add("Canada");
    list.add("Russia");
    list.add("France");

    std::cout << std::boolalpha;
    std::cout << "Contains Canada: " << list.contains("Canada") << std::endl;
    std::cout << "Contains Germany: " << list.contains("Germany") << std::endl;

    return 0;
}

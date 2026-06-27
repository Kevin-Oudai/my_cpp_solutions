#include "../BST.h"
#include <iostream>
#include <string>

int main()
{
    std::string values[] = {"George", "Michael", "Tom", "Adam", "Jones", "Peter", "Daniel"};
    BST<std::string> tree(values, 7);

    std::cout << "Search Peter: " << (tree.search("Peter") ? "found" : "not found") << std::endl;
    std::cout << "Search Kevin: " << (tree.search("Kevin") ? "found" : "not found") << std::endl;

    return 0;
}

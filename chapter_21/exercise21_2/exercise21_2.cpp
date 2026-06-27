#include "../BST.h"
#include <iostream>

int main()
{
    int values[] = {60, 55, 100, 45, 57, 67, 107, 59, 101};
    BST<int> tree(values, 9);

    std::cout << "Breadth-first: ";
    tree.breadthFirstTraversal();
    std::cout << std::endl;

    return 0;
}

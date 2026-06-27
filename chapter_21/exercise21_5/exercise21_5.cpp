#include "../BST.h"
#include <iostream>

int main()
{
    int values[] = {2, 4, 3, 1, 8, 5, 6, 7};
    BST<int> tree(values, 8);

    std::cout << "Preorder using stack: ";
    tree.preorderWithStack();
    std::cout << std::endl;

    return 0;
}

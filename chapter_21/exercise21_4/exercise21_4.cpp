#include "../BST.h"
#include <iostream>

int main()
{
    int values[] = {2, 4, 3, 1, 8, 5, 6, 7};
    BST<int> tree(values, 8);

    std::cout << "Inorder using stack: ";
    tree.inorderWithStack();
    std::cout << std::endl;

    return 0;
}

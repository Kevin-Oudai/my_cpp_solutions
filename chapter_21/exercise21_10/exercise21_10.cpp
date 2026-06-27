#include "../BST.h"
#include <iostream>

int main()
{
    int fullValues[] = {4, 2, 6, 1, 3, 5, 7};
    BST<int> fullTree(fullValues, 7);

    int incompleteValues[] = {4, 2, 6, 1, 3, 5};
    BST<int> incompleteTree(incompleteValues, 6);

    std::cout << "First tree is full: " << (fullTree.isFullBST() ? "true" : "false") << std::endl;
    std::cout << "Second tree is full: " << (incompleteTree.isFullBST() ? "true" : "false") << std::endl;

    return 0;
}

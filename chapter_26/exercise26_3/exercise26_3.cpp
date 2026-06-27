#include "../AVLTree.h"
#include <iostream>

int main()
{
    AVLTree<int> tree;
    int values[] = {25, 20, 34, 5, 30, 50};

    for (int i = 0; i < 6; i++)
        tree.insert(values[i]);

    AVLTree<int> copy(tree);
    AVLTree<int> assigned;
    assigned = tree;

    std::cout << "Original inorder: ";
    tree.inorder();
    std::cout << std::endl << "Copy inorder: ";
    copy.inorder();
    std::cout << std::endl << "Assigned inorder: ";
    assigned.inorder();
    std::cout << std::endl;

    return 0;
}

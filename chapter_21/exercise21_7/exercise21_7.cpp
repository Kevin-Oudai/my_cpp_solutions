#include "../BST.h"
#include <iostream>

int main()
{
    BST<int> tree;

    for (int i = 1; i <= 100; i++)
        tree.insert(i);

    TreeNode<int>* node = tree.findNode(100);
    TreeNode<int>* parent = tree.getParent(*node);

    if (parent != NULL)
        std::cout << "Parent of 100: " << parent->element << std::endl;

    tree.displayLeafPaths();

    return 0;
}

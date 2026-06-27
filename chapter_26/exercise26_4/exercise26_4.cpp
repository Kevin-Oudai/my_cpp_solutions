#include "../AVLTree.h"
#include <iostream>

int main()
{
    AVLTree<int> tree;

    for (int i = 1; i <= 100; i++)
        tree.insert(i);

    tree.displayLeafPaths();

    return 0;
}

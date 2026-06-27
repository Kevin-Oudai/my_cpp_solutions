#include "../AVLTree.h"
#include <iostream>

int main()
{
    AVLTree<int> tree;
    int values[] = {25, 20, 34, 5, 30, 50};

    for (int i = 0; i < 6; i++)
        tree.insert(values[i]);

    for (int k = 1; k <= tree.getSize(); k++)
        std::cout << k << "th smallest: " << tree.find(k) << std::endl;

    return 0;
}

#include "../SplayTree.h"
#include <iostream>

int main()
{
    SplayTree<int> tree;

    for (int i = 1; i <= 10; i++)
        tree.insert(i);

    std::cout << "Root after inserting 1 through 10: " << tree.getRootElement() << std::endl;
    tree.search(4);
    std::cout << "Root after searching 4: " << tree.getRootElement() << std::endl;
    tree.remove(4);
    std::cout << "Root after removing 4: " << tree.getRootElement() << std::endl;
    std::cout << "Inorder: ";
    tree.inorder();
    std::cout << std::endl;

    return 0;
}

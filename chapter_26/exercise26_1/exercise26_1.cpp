#include "../AVLTree.h"
#include "../../chapter_21/BST.h"
#include <iostream>

int main()
{
    BST<char> bst;
    AVLTree<char> avl;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        bst.insert(ch);
        avl.insert(ch);
    }

    std::cout << "BST inorder: ";
    bst.inorder();
    std::cout << std::endl << "BST preorder: ";
    bst.preorder();
    std::cout << std::endl << "BST postorder: ";
    bst.postorder();

    std::cout << std::endl << "AVL inorder: ";
    avl.inorder();
    std::cout << std::endl << "AVL preorder: ";
    avl.preorder();
    std::cout << std::endl << "AVL postorder: ";
    avl.postorder();
    std::cout << std::endl;

    return 0;
}

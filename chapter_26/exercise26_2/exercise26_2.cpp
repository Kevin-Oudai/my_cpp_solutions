#include "../AVLTree.h"
#include "../../chapter_21/BST.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    int size = std::getenv("QUICK_TEST") == NULL ? 500000 : 50000;
    std::vector<int> values;

    for (int i = 0; i < size; i++)
        values.push_back(i);

    std::mt19937 engine(1);
    std::shuffle(values.begin(), values.end(), engine);

    BST<int> bst;
    clock_t start = clock();
    for (int i = 0; i < size; i++)
        bst.insert(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        bst.search(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        bst.remove(values[i]);
    double bstTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::shuffle(values.begin(), values.end(), engine);
    AVLTree<int> avl;
    start = clock();
    for (int i = 0; i < size; i++)
        avl.insert(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        avl.search(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        avl.remove(values[i]);
    double avlTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << "Test size: " << size << std::endl;
    std::cout << "BST time: " << bstTime << " seconds" << std::endl;
    std::cout << "AVL time: " << avlTime << " seconds" << std::endl;

    return 0;
}

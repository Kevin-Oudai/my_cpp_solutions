#include "../AVLTree.h"
#include "../SplayTree.h"
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

    std::mt19937 engine(2);
    std::shuffle(values.begin(), values.end(), engine);

    AVLTree<int> avl;
    clock_t start = clock();
    for (int i = 0; i < size; i++)
        avl.insert(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        avl.search(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        avl.remove(values[i]);
    double avlTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::shuffle(values.begin(), values.end(), engine);
    SplayTree<int> splay;
    start = clock();
    for (int i = 0; i < size; i++)
        splay.insert(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        splay.search(values[i]);
    std::shuffle(values.begin(), values.end(), engine);
    for (int i = 0; i < size; i++)
        splay.remove(values[i]);
    double splayTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << "Test size: " << size << std::endl;
    std::cout << "AVL time: " << avlTime << " seconds" << std::endl;
    std::cout << "Splay time: " << splayTime << " seconds" << std::endl;

    return 0;
}

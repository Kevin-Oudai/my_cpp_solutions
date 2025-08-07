#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>

class Tree
{
public:
    Tree();
    Tree(int root, std::vector<int> &parent, std::vector<int> &searchOrders)
    {
        this->root = root;
        this->parent = parent;
        this->searchOrders = searchOrders;
    }
    int getRoot() const
    {
        return root;
    }
    int getParent(int v) const
    {
        return parent[v];
    }
    std::vector<int> getSearchOrders() const
    {
        return searchOrders;
    }
    int getNumberOfVerticesFound() const
    {
        return searchOrders.size();
    }
    std::vector<int> getPath(int v) const
    {
        std::vector<int> path;

        do
        {
            path.push_back(v);
            v = parent[v];
        } while (v != -1);
        return path;
    }

    void printTree() const
    {
        std::cout << "Root is: " << root << std::endl;
        std::cout << "Edges: ";
        for (unsigned i = 0; i < searchOrders.size(); i++)
        {
            if (parent[searchOrders[i]] != -1)
            {
                std::cout << "(" << parent[searchOrders[i]] << ", " << searchOrders[i] << ") ";
            }
        }
        std::cout << std::endl;
    }

private:
    int root;
    std::vector<int> parent;
    std::vector<int> searchOrders;
};

#endif
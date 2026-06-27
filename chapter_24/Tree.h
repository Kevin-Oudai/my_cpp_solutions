#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

class Tree
{
public:
    Tree()
    {
        root = -1;
    }

    Tree(int root, const std::vector<int>& parent, const std::vector<int>& searchOrders)
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
        return static_cast<int>(searchOrders.size());
    }

    int depth(int v) const
    {
        int result = 0;

        while (v != root && v >= 0 && v < static_cast<int>(parent.size()))
        {
            v = parent[v];
            result++;
        }

        return result;
    }

    std::vector<int> getPath(int v) const
    {
        std::vector<int> path;

        if (v < 0 || v >= static_cast<int>(parent.size()))
            return path;

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
        for (int i = 0; i < static_cast<int>(searchOrders.size()); i++)
        {
            if (parent[searchOrders[i]] != -1)
                std::cout << "(" << parent[searchOrders[i]] << ", " << searchOrders[i] << ") ";
        }
        std::cout << std::endl;
    }

private:
    int root;
    std::vector<int> parent;
    std::vector<int> searchOrders;
};

#endif

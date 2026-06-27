#ifndef MST_H
#define MST_H

#include <iostream>
#include <vector>

class MST
{
public:
    MST()
    {
        root = -1;
        totalWeight = 0;
    }

    MST(int root, const std::vector<int>& parent, const std::vector<int>& searchOrders, double totalWeight)
    {
        this->root = root;
        this->parent = parent;
        this->searchOrders = searchOrders;
        this->totalWeight = totalWeight;
    }

    int getRoot() const
    {
        return root;
    }

    int getParent(int v) const
    {
        return parent[v];
    }

    double getTotalWeight() const
    {
        return totalWeight;
    }

    std::vector<int> getSearchOrders() const
    {
        return searchOrders;
    }

    void printTree() const
    {
        std::cout << "Root is: " << root << std::endl;
        std::cout << "Edges: ";

        for (int i = 0; i < static_cast<int>(searchOrders.size()); i++)
        {
            int v = searchOrders[i];
            if (parent[v] != -1)
                std::cout << "(" << parent[v] << ", " << v << ") ";
        }

        std::cout << std::endl;
    }

private:
    int root;
    std::vector<int> parent;
    std::vector<int> searchOrders;
    double totalWeight;
};

#endif

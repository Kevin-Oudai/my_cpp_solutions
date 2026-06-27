#ifndef SHORTESTPATHTREE_H
#define SHORTESTPATHTREE_H

#include <iostream>
#include <vector>

class ShortestPathTree
{
public:
    ShortestPathTree()
    {
        source = -1;
    }

    ShortestPathTree(int source, const std::vector<int>& parent, const std::vector<int>& searchOrders, const std::vector<double>& cost)
    {
        this->source = source;
        this->parent = parent;
        this->searchOrders = searchOrders;
        this->cost = cost;
    }

    int getSource() const
    {
        return source;
    }

    double getCost(int v) const
    {
        return cost[v];
    }

    std::vector<int> getPath(int v) const
    {
        std::vector<int> path;

        while (v != -1)
        {
            path.push_back(v);
            v = parent[v];
        }

        std::vector<int> result;
        for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--)
            result.push_back(path[i]);

        return result;
    }

    void printAllPaths() const
    {
        for (int i = 0; i < static_cast<int>(cost.size()); i++)
        {
            std::cout << "A path from " << source << " to " << i << ": ";
            std::vector<int> path = getPath(i);
            for (int j = 0; j < static_cast<int>(path.size()); j++)
                std::cout << path[j] << " ";
            std::cout << "(cost: " << cost[i] << ")" << std::endl;
        }
    }

private:
    int source;
    std::vector<int> parent;
    std::vector<int> searchOrders;
    std::vector<double> cost;
};

#endif

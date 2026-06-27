#ifndef SHORTESTPATHWITHAVL_H
#define SHORTESTPATHWITHAVL_H

#include "AVLTree.h"
#include "../chapter_25/WeightedGraph.h"

class CostVertex
{
public:
    double cost;
    int vertex;

    CostVertex()
    {
        cost = 0;
        vertex = 0;
    }

    CostVertex(double cost, int vertex)
    {
        this->cost = cost;
        this->vertex = vertex;
    }

    bool operator<(const CostVertex& other) const
    {
        if (cost != other.cost)
            return cost < other.cost;

        return vertex < other.vertex;
    }

    bool operator>(const CostVertex& other) const
    {
        return other < *this;
    }

    bool operator==(const CostVertex& other) const
    {
        return cost == other.cost && vertex == other.vertex;
    }
};

inline ShortestPathTree getShortestPathUsingAVL(WeightedGraph<int>& graph, int sourceVertex)
{
    int n = graph.getSize();
    std::vector<std::vector<double> > matrix = graph.getAdjacencyMatrix();
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<bool> isInT(n, false);
    std::vector<int> searchOrders;
    AVLTree<CostVertex> candidates;

    for (int i = 0; i < n; i++)
    {
        if (i == sourceVertex)
            cost[i] = 0;

        candidates.insert(CostVertex(cost[i], i));
    }

    while (candidates.getSize() > 0)
    {
        CostVertex current = candidates.getMinimum();
        candidates.remove(current);

        int u = current.vertex;
        if (current.cost >= WEIGHTED_INFINITY)
            break;

        isInT[u] = true;
        searchOrders.push_back(u);

        for (int v = 0; v < n; v++)
        {
            if (!isInT[v] && matrix[u][v] < WEIGHTED_INFINITY && cost[u] + matrix[u][v] < cost[v])
            {
                candidates.remove(CostVertex(cost[v], v));
                cost[v] = cost[u] + matrix[u][v];
                parent[v] = u;
                candidates.insert(CostVertex(cost[v], v));
            }
        }
    }

    return ShortestPathTree(sourceVertex, parent, searchOrders, cost);
}

#endif

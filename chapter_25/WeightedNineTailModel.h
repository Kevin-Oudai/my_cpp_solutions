#ifndef WEIGHTEDNINETAILMODEL_H
#define WEIGHTEDNINETAILMODEL_H

#include "WeightedGraph.h"
#include <queue>
#include <vector>

class WeightedNineTailModel
{
public:
    WeightedNineTailModel(int weightMultiplier)
    {
        this->weightMultiplier = weightMultiplier;
        target = 511;
        buildShortestPaths();
    }

    std::vector<int> getShortestPath(int node) const
    {
        std::vector<int> path;

        while (node != -1)
        {
            path.push_back(node);
            if (node == target)
                break;
            node = parent[node];
        }

        return path;
    }

    double getCost(int node) const
    {
        return cost[node];
    }

    int getDepth(int node) const
    {
        return static_cast<int>(getShortestPath(node).size()) - 1;
    }

private:
    int weightMultiplier;
    int target;
    std::vector<int> parent;
    std::vector<double> cost;

    int flip(int node, int position) const
    {
        int row = position / 3;
        int column = position % 3;
        int result = node;

        int positions[][2] = {
            {row, column}, {row - 1, column}, {row + 1, column}, {row, column - 1}, {row, column + 1}
        };

        for (int i = 0; i < 5; i++)
        {
            int r = positions[i][0];
            int c = positions[i][1];

            if (r >= 0 && r < 3 && c >= 0 && c < 3)
                result ^= 1 << (r * 3 + c);
        }

        return result;
    }

    int flipCount(int position) const
    {
        int row = position / 3;
        int column = position % 3;
        int count = 1;

        if (row > 0)
            count++;
        if (row < 2)
            count++;
        if (column > 0)
            count++;
        if (column < 2)
            count++;

        return count;
    }

    void buildShortestPaths()
    {
        parent.assign(512, -1);
        cost.assign(512, WEIGHTED_INFINITY);
        std::vector<bool> done(512, false);

        cost[target] = 0;

        for (int count = 0; count < 512; count++)
        {
            int u = -1;
            double best = WEIGHTED_INFINITY;

            for (int i = 0; i < 512; i++)
            {
                if (!done[i] && cost[i] < best)
                {
                    best = cost[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            done[u] = true;

            for (int position = 0; position < 9; position++)
            {
                int v = flip(u, position);
                double weight = flipCount(position) * weightMultiplier;

                if (!done[v] && cost[u] + weight < cost[v])
                {
                    cost[v] = cost[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }
};

#endif

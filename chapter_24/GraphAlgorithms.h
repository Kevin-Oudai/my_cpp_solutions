#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

#include "Graph.h"
#include <vector>

template<typename V>
Graph<V> maxInducedSubgraph(Graph<V> g, int k)
{
    int n = g.getSize();
    std::vector<bool> active(n, true);
    bool changed = true;

    while (changed)
    {
        changed = false;

        for (int u = 0; u < n; u++)
        {
            if (!active[u])
                continue;

            int degree = 0;
            std::vector<int> neighbors = g.getNeighbors(u);

            for (int i = 0; i < static_cast<int>(neighbors.size()); i++)
            {
                if (active[neighbors[i]])
                    degree++;
            }

            if (degree < k)
            {
                active[u] = false;
                changed = true;
            }
        }
    }

    std::vector<V> vertices;
    std::vector<int> oldToNew(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (active[i])
        {
            oldToNew[i] = static_cast<int>(vertices.size());
            vertices.push_back(g.getVertex(i));
        }
    }

    if (vertices.empty())
        return Graph<V>();

    std::vector<Edge> edges;
    std::vector<Edge> originalEdges = g.getEdges();

    for (int i = 0; i < static_cast<int>(originalEdges.size()); i++)
    {
        int u = originalEdges[i].u;
        int v = originalEdges[i].v;

        if (active[u] && active[v])
            edges.push_back(Edge(oldToNew[u], oldToNew[v]));
    }

    return Graph<V>(vertices, edges);
}

#endif

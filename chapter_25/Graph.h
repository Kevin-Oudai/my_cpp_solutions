#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

template<typename V>
class Graph
{
public:
    Graph()
    {
    }

    virtual ~Graph()
    {
        clear();
    }

    int getSize() const
    {
        return static_cast<int>(vertices.size());
    }

    V getVertex(int index) const
    {
        return vertices[index];
    }

    std::vector<V> getVertices() const
    {
        return vertices;
    }

    std::vector<int> getNeighbors(int u) const
    {
        std::vector<int> result;

        for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            result.push_back(neighbors[u][i]->v);

        return result;
    }

    virtual bool addVertex(V v)
    {
        if (std::find(vertices.begin(), vertices.end(), v) != vertices.end())
            return false;

        vertices.push_back(v);
        neighbors.push_back(std::vector<Edge*>());
        return true;
    }

    bool addEdge(int u, int v)
    {
        return createEdge(new Edge(u, v));
    }

    void clear()
    {
        for (int i = 0; i < static_cast<int>(neighbors.size()); i++)
        {
            for (int j = 0; j < static_cast<int>(neighbors[i].size()); j++)
                delete neighbors[i][j];
        }

        neighbors.clear();
        vertices.clear();
    }

protected:
    std::vector<V> vertices;
    std::vector<std::vector<Edge*> > neighbors;

    bool createEdge(Edge* e)
    {
        if (e->u < 0 || e->u > getSize() - 1)
        {
            std::stringstream ss;
            ss << e->u;
            delete e;
            throw std::invalid_argument("No such edge: " + ss.str());
        }

        if (e->v < 0 || e->v > getSize() - 1)
        {
            std::stringstream ss;
            ss << e->v;
            delete e;
            throw std::invalid_argument("No such edge: " + ss.str());
        }

        for (int i = 0; i < static_cast<int>(neighbors[e->u].size()); i++)
        {
            if (neighbors[e->u][i]->v == e->v)
            {
                delete e;
                return false;
            }
        }

        neighbors[e->u].push_back(e);
        return true;
    }
};

#endif

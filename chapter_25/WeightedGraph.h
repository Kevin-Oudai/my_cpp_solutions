#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include "WeightedEdge.h"
#include "MST.h"
#include "ShortestPathTree.h"
#include <vector>

template <typename V>
class WeightedGraph : public Graph<V>
{
public:
    WeightedGraph();
    WeightedGraph(std::vector<V> &vertices, std::vector<WeightedEdge> &edges);
    WeightedGraph(int numberOfVertices, std::vector<WeightedEdge> &edges);
    void WeightedGraph<V>::printWeightedEdges();
    bool addEdge(int u, int v, double w);
    MST getMinimumSpanningTree();
    MST getMinimumSpanningTree(int startingVertex);
    ShortestPathTree getShortestPath(int sourceVertex);
};

const int INFINITY = 2147483647;

template <typename V>
WeightedGraph<V>::WeightedGraph()
{
}

template <typename V>
WeightedGraph<V>::WeightedGraph(std::vector<V> &vertices, std::vector<WeightedEdge> &edges)
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        addVertex(vertices[i]);
    }

    for (unsigned i = 0; i < edges.size(); i++)
    {
        addEdge(edges[i].u, edges[i].v, edges[i].weight);
    }
}

template <typename V>
WeightedGraph<V>::WeightedGraph(int numberOfVertices, std::vector<WeightedEdge> &edges)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        addVertex(i);
    }

    for (unsigned i = 0; i < edges.size(); i++)
    {
        addEdge(edges[i].u, edges[i].v, edges[i].weight);
    }
}

template <typename V>
void WeightedGraph<V>::printWeightedEdges()
{
    for (int i = 0; i < getSize(); i++)
    {
        std::cout << "Vertex " << getVertex(i) << "(" << i << "): ";

        for (Edge *e : neighbors[i]))
            {
                std::cout << "(" << e->u << ", " << e->v << ", " << static_cast<WeightedEdge *>(e)->weight << ") ";
            }
        std::cout << std::endl;
    }
}
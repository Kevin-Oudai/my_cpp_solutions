#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Tree.h"
#include <vector>
#include <queue>
#include <stdexcept>
#include <sstream>
#include <algorithm>

template <typename V>
class Graph
{
public:
    Graph();
    Graph(std::vector<V> &vertices, int edges[][2], int numberOfEdges);
    Graph(int numberOfVertices, int edges[][2], int numberOfEdges);
    Graph(std::vector<V> &vertices, std::vector<Edge> &edges);
    Graph(int numberOfVertices, std::vector<Edge> &edges);
    int getSize() const;
    int getDegree(int v) const;
    V getVertex(int index) const;
    int getIndex(V v) const;
    std::vector<V> getVertices() const;
    std::vector<int> getNeighbors(int v) const;
    void printEdges() const;
    void printAdjacencyMatrix() const;
    void clear();
    virtual bool addVertex(V v);
    bool addEdge(int u, int v);
    Tree dfs(int v) const;
    Tree bfs(int v) const;

protected:
    std::vector<V> vertices;
    std::vector<std::vector<Edge *>> neighbors;
    bool createEdge(Edge *e);

private:
    void createAdjacencyLists(int numberOfVertices, int edges[][2], int numberOfEdges);
    void createAdjacencyLists(int numberOfVertices, std::vector<Edge> &edges);
    void dfs(int v, std::vector<int> &parent, std::vector<int> &searchOrders, std::vector<bool> &isVisited) const;
};

template <typename V>
Graph<V>::Graph()
{
}

template <typename V>
Graph<V>::Graph(std::vector<V> &vertices, int edges[][2], int numberOfEdges)
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        addVertex(vertices[i]);
    }
    createAdjacencyLists(vertices.size(), edges, numberOfEdges);
}

template <typename V>
Graph<V>::Graph(int numberOfVertices, int edges[][2], int numberOfEdges)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        addVertex(i);
    }
    createAdjacencyLists(numberOfVertices, edges, numberOfEdges);
}

template <typename V>
Graph<V>::Graph(std::vector<V> &vertices, std::vector<Edge> &edges)
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        addVertex(vertices[i]);
    }
    createAdjacencyLists(vertices.size(), edges);
}

template <typename V>
Graph<V>::Graph(int numberOfVertices, std::vector<Edge> &edges)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        addVertex(i);
    }
    createAdjacencyLists(numberOfVertices, edges);
}

template <typename V>
void Graph<V>::createAdjacencyLists(int numberOfVertices, int edges[][2], int numberOfEdges)
{
    for (int i = 0; i < numberOfEdges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(u, v);
    }
}

template <typename V>
void Graph<V>::createAdjacencyLists(int numberOfVertices, std::vector<Edge> &edges)
{
    for (unsigned i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        addEdge(u, v);
    }
}

template <typename V>
int Graph<V>::getSize() const
{
    return vertices.size();
}

template <typename V>
int Graph<V>::getDegree(int v) const
{
    return neighbors[v].size();
}

template <typename V>
V Graph<V>::getVertex(int index) const
{
    return vertices[index];
}

template <typename V>
int Graph<V>::getIndex(V v) const
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == v)
        {
            return i;
        }
    }
    return -1;
}

template <typename V>
std::vector<V> Graph<V>::getVertices() const
{
    return vertices;
}

template <typename V>
std::vector<int> Graph<V>::getNeighbors(int u) const
{
    std::vector<int> result;
    for (Edge *e : neighbors[u])
    {
        result.push_back(e->v);
    }
    return result;
}

template <typename V>
void Graph<V>::printEdges() const
{
    for (unsigned u = 0; u < neighbors.size(); u++)
    {
        std::cout << "Vertex " << getVertex(u) << "(" << u << "): ";
        for (Edge *e : neighbors[u])
        {
            std::cout << "(" << getVertex(e->u) << ", " << getVertex(e->v) << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename V>
void Graph<V>::printAdjacencyMatrix() const
{
    std::vector<std::vector<int>> adjacencyMatrix(getSize());

    for (int i = 0; i < getSize(); i++)
    {
        adjacencyMatrix[i] = std::vector<int>(getSize());
    }

    for (unsigned i = 0; i < neighbors.size(); i++)
    {
        for (Edge *e : neighbors[i])
        {
            adjacencyMatrix[i][e->v] = 1;
        }
    }

    for (unsigned i = 0; i < adjacencyMatrix.size(); i++)
    {
        for (unsigned j = 0; j < adjacencyMatrix[i].size(); j++)
        {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename V>
void Graph<V>::clear()
{
    vertices.clear();
    for (int i = 0; i < getSize(); i++)
        for (Edge *e : neighbors[i])
            delete e;
    neighbors.clear();
}

template <typename V>
bool Graph<V>::addVertex(V v)
{
    if (std::find(vertices.begin(), vertices.end(), v) == vertices.end())
    {
        vertices.push_back(v);
        neighbors.push_back(std::vector<Edge *>(0));
        return true;
    }
    return false;
}

template <typename V>
bool Graph<V>::createEdge(Edge *e)
{
    if (e->u < 0 || e->u > getSize() - 1)
    {
        std::stringstream ss;
        ss << e->u;
        throw std::invalid_argument("No such edge: " + ss.str());
    }
    if (e->v < 0 || e->v > getSize() - 1)
    {
        std::stringstream ss;
        ss << e->v;
        throw std::invalid_argument("No such edge: " + ss.str());
    }

    std::vector<int> listOfNeighbors = getNeighbors(e->u);
    if (std::find(listOfNeighbors.begin(), listOfNeighbors.end(), e->v) == listOfNeighbors.end())
    {
        neighbors[e->u].push_back(e);
        return true;
    }
    return false;
}

template <typename V>
bool Graph<V>::addEdge(int u, int v)
{
    return createEdge(new Edge(u, v));
}

template <typename V>
Tree Graph<V>::dfs(int u) const
{
    std::vector<int> searchOrders;
    std::vector<int> parent(vertices.size());
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        parent[i] = -1;
    }

    std::vector<bool> isVisited(vertices.size());
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        isVisited[i] = false;
    }
    dfs(u, parent, searchOrders, isVisited);
    return Tree(u, parent, searchOrders);
}

template <typename V>
void Graph<V>::dfs(int u, std::vector<int> &parent, std::vector<int> &searchOrders, std::vector<bool> &isVisited) const
{
    searchOrders.push_back(u);
    isVisited[u] = true;
    for (Edge *e : neighbors[u])
    {
        if (!isVisited[e->v])
        {
            parent[e->v] = u;
            dfs(e->v, parent, searchOrders, isVisited);
        }
    }
}

template <typename V>
Tree Graph<V>::bfs(int v) const
{
    std::vector<int> searchOrders;
    std::vector<int> parent(vertices.size());
    for (int i = 0; i < getSize(); i++)
    {
        parent[i] = -1;
    }
    std::queue<int> queue;
    std::vector<bool> isVisited(getSize());
    queue.push(v);
    isVisited[v] = true;

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        searchOrders.push_back(u);
        for (Edge *e : neighbors[u])
        {
            int w = e->v;
            if (!isVisited[w])
            {
                queue.push(w);
                parent[w] = u;
                isVisited[w] = true;
            }
        }
    }
    return Tree(v, parent, searchOrders);
}

#endif

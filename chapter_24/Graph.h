#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Tree.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <vector>

template<typename V>
class Graph
{
public:
    Graph();
    Graph(const Graph<V>& graph);
    Graph(std::vector<V>& vertices, int edges[][2], int numberOfEdges);
    Graph(int numberOfVertices, int edges[][2], int numberOfEdges);
    Graph(std::vector<V>& vertices, std::vector<Edge>& edges);
    Graph(int numberOfVertices, std::vector<Edge>& edges);
    virtual ~Graph();
    Graph<V>& operator=(const Graph<V>& graph);

    int getSize() const;
    int getDegree(int v) const;
    V getVertex(int index) const;
    int getIndex(V v) const;
    std::vector<V> getVertices() const;
    std::vector<int> getNeighbors(int v) const;
    std::vector<Edge> getEdges() const;
    void printEdges() const;
    void printAdjacencyMatrix() const;
    void clear();
    virtual bool addVertex(V v);
    bool addEdge(int u, int v);
    Tree dfs(int v) const;
    Tree dfsWithStack(int v) const;
    Tree bfs(int v) const;
    std::vector<std::vector<int> > getConnectedComponents() const;
    std::vector<int> getPath(int u, int v) const;
    bool containsCyclic() const;
    std::vector<int> getACycle() const;
    bool isBipartite() const;
    std::vector<std::vector<int> > getBipartiteSets() const;

protected:
    std::vector<V> vertices;
    std::vector<std::vector<Edge*> > neighbors;
    bool createEdge(Edge* e);

private:
    void copyFrom(const Graph<V>& graph);
    void createAdjacencyLists(int numberOfVertices, int edges[][2], int numberOfEdges);
    void createAdjacencyLists(int numberOfVertices, std::vector<Edge>& edges);
    void dfs(int v, std::vector<int>& parent, std::vector<int>& searchOrders, std::vector<bool>& isVisited) const;
    bool containsCycle(int u, int parent, std::vector<bool>& isVisited) const;
    bool findCycle(int u, int parent, std::vector<bool>& isVisited, std::vector<int>& parentVector, std::vector<int>& cycle) const;
};

template<typename V>
Graph<V>::Graph()
{
}

template<typename V>
Graph<V>::Graph(const Graph<V>& graph)
{
    copyFrom(graph);
}

template<typename V>
Graph<V>::Graph(std::vector<V>& vertices, int edges[][2], int numberOfEdges)
{
    for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        addVertex(vertices[i]);

    createAdjacencyLists(static_cast<int>(vertices.size()), edges, numberOfEdges);
}

template<typename V>
Graph<V>::Graph(int numberOfVertices, int edges[][2], int numberOfEdges)
{
    for (int i = 0; i < numberOfVertices; i++)
        addVertex(i);

    createAdjacencyLists(numberOfVertices, edges, numberOfEdges);
}

template<typename V>
Graph<V>::Graph(std::vector<V>& vertices, std::vector<Edge>& edges)
{
    for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        addVertex(vertices[i]);

    createAdjacencyLists(static_cast<int>(vertices.size()), edges);
}

template<typename V>
Graph<V>::Graph(int numberOfVertices, std::vector<Edge>& edges)
{
    for (int i = 0; i < numberOfVertices; i++)
        addVertex(i);

    createAdjacencyLists(numberOfVertices, edges);
}

template<typename V>
Graph<V>::~Graph()
{
    clear();
}

template<typename V>
Graph<V>& Graph<V>::operator=(const Graph<V>& graph)
{
    if (this != &graph)
    {
        clear();
        copyFrom(graph);
    }

    return *this;
}

template<typename V>
void Graph<V>::copyFrom(const Graph<V>& graph)
{
    for (int i = 0; i < static_cast<int>(graph.vertices.size()); i++)
        addVertex(graph.vertices[i]);

    for (int u = 0; u < static_cast<int>(graph.neighbors.size()); u++)
    {
        for (int i = 0; i < static_cast<int>(graph.neighbors[u].size()); i++)
            addEdge(graph.neighbors[u][i]->u, graph.neighbors[u][i]->v);
    }
}

template<typename V>
void Graph<V>::createAdjacencyLists(int numberOfVertices, int edges[][2], int numberOfEdges)
{
    for (int i = 0; i < numberOfEdges; i++)
        addEdge(edges[i][0], edges[i][1]);
}

template<typename V>
void Graph<V>::createAdjacencyLists(int numberOfVertices, std::vector<Edge>& edges)
{
    for (int i = 0; i < static_cast<int>(edges.size()); i++)
        addEdge(edges[i].u, edges[i].v);
}

template<typename V>
int Graph<V>::getSize() const
{
    return static_cast<int>(vertices.size());
}

template<typename V>
int Graph<V>::getDegree(int v) const
{
    return static_cast<int>(neighbors[v].size());
}

template<typename V>
V Graph<V>::getVertex(int index) const
{
    return vertices[index];
}

template<typename V>
int Graph<V>::getIndex(V v) const
{
    for (int i = 0; i < static_cast<int>(vertices.size()); i++)
    {
        if (vertices[i] == v)
            return i;
    }

    return -1;
}

template<typename V>
std::vector<V> Graph<V>::getVertices() const
{
    return vertices;
}

template<typename V>
std::vector<int> Graph<V>::getNeighbors(int u) const
{
    std::vector<int> result;

    for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
        result.push_back(neighbors[u][i]->v);

    return result;
}

template<typename V>
std::vector<Edge> Graph<V>::getEdges() const
{
    std::vector<Edge> result;

    for (int u = 0; u < static_cast<int>(neighbors.size()); u++)
    {
        for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            result.push_back(Edge(neighbors[u][i]->u, neighbors[u][i]->v));
    }

    return result;
}

template<typename V>
void Graph<V>::printEdges() const
{
    for (int u = 0; u < static_cast<int>(neighbors.size()); u++)
    {
        std::cout << "Vertex " << getVertex(u) << "(" << u << "): ";
        for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            std::cout << "(" << getVertex(neighbors[u][i]->u) << ", " << getVertex(neighbors[u][i]->v) << ") ";
        std::cout << std::endl;
    }
}

template<typename V>
void Graph<V>::printAdjacencyMatrix() const
{
    std::vector<std::vector<int> > adjacencyMatrix(getSize());

    for (int i = 0; i < getSize(); i++)
        adjacencyMatrix[i] = std::vector<int>(getSize());

    for (int i = 0; i < static_cast<int>(neighbors.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(neighbors[i].size()); j++)
            adjacencyMatrix[i][neighbors[i][j]->v] = 1;
    }

    for (int i = 0; i < static_cast<int>(adjacencyMatrix.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(adjacencyMatrix[i].size()); j++)
            std::cout << adjacencyMatrix[i][j] << " ";
        std::cout << std::endl;
    }
}

template<typename V>
void Graph<V>::clear()
{
    for (int i = 0; i < static_cast<int>(neighbors.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(neighbors[i].size()); j++)
            delete neighbors[i][j];
    }

    neighbors.clear();
    vertices.clear();
}

template<typename V>
bool Graph<V>::addVertex(V v)
{
    if (std::find(vertices.begin(), vertices.end(), v) != vertices.end())
        return false;

    vertices.push_back(v);
    neighbors.push_back(std::vector<Edge*>());
    return true;
}

template<typename V>
bool Graph<V>::createEdge(Edge* e)
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

    std::vector<int> listOfNeighbors = getNeighbors(e->u);
    if (std::find(listOfNeighbors.begin(), listOfNeighbors.end(), e->v) != listOfNeighbors.end())
    {
        delete e;
        return false;
    }

    neighbors[e->u].push_back(e);
    return true;
}

template<typename V>
bool Graph<V>::addEdge(int u, int v)
{
    return createEdge(new Edge(u, v));
}

template<typename V>
Tree Graph<V>::dfs(int u) const
{
    std::vector<int> searchOrders;
    std::vector<int> parent(vertices.size(), -1);
    std::vector<bool> isVisited(vertices.size(), false);

    dfs(u, parent, searchOrders, isVisited);

    return Tree(u, parent, searchOrders);
}

template<typename V>
void Graph<V>::dfs(int u, std::vector<int>& parent, std::vector<int>& searchOrders, std::vector<bool>& isVisited) const
{
    searchOrders.push_back(u);
    isVisited[u] = true;

    for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
    {
        int v = neighbors[u][i]->v;
        if (!isVisited[v])
        {
            parent[v] = u;
            dfs(v, parent, searchOrders, isVisited);
        }
    }
}

template<typename V>
Tree Graph<V>::dfsWithStack(int v) const
{
    std::vector<int> searchOrders;
    std::vector<int> parent(vertices.size(), -1);
    std::vector<bool> isVisited(vertices.size(), false);
    std::vector<int> stack;

    stack.push_back(v);
    isVisited[v] = true;

    while (!stack.empty())
    {
        int u = stack[stack.size() - 1];
        stack.pop_back();
        searchOrders.push_back(u);

        for (int i = static_cast<int>(neighbors[u].size()) - 1; i >= 0; i--)
        {
            int w = neighbors[u][i]->v;
            if (!isVisited[w])
            {
                stack.push_back(w);
                isVisited[w] = true;
                parent[w] = u;
            }
        }
    }

    return Tree(v, parent, searchOrders);
}

template<typename V>
Tree Graph<V>::bfs(int v) const
{
    std::vector<int> searchOrders;
    std::vector<int> parent(vertices.size(), -1);
    std::vector<bool> isVisited(vertices.size(), false);
    std::queue<int> queue;

    queue.push(v);
    isVisited[v] = true;

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        searchOrders.push_back(u);

        for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
        {
            int w = neighbors[u][i]->v;
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

template<typename V>
std::vector<std::vector<int> > Graph<V>::getConnectedComponents() const
{
    std::vector<std::vector<int> > components;
    std::vector<bool> visited(getSize(), false);

    for (int start = 0; start < getSize(); start++)
    {
        if (visited[start])
            continue;

        std::vector<int> component;
        std::queue<int> queue;
        queue.push(start);
        visited[start] = true;

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();
            component.push_back(u);

            for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            {
                int v = neighbors[u][i]->v;
                if (!visited[v])
                {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }

        components.push_back(component);
    }

    return components;
}

template<typename V>
std::vector<int> Graph<V>::getPath(int u, int v) const
{
    Tree tree = bfs(u);
    std::vector<int> reversePath = tree.getPath(v);
    std::vector<int> path;

    if (reversePath.empty() || reversePath[reversePath.size() - 1] != u)
        return path;

    for (int i = static_cast<int>(reversePath.size()) - 1; i >= 0; i--)
        path.push_back(reversePath[i]);

    return path;
}

template<typename V>
bool Graph<V>::containsCyclic() const
{
    std::vector<bool> isVisited(getSize(), false);

    for (int i = 0; i < getSize(); i++)
    {
        if (!isVisited[i] && containsCycle(i, -1, isVisited))
            return true;
    }

    return false;
}

template<typename V>
bool Graph<V>::containsCycle(int u, int parent, std::vector<bool>& isVisited) const
{
    isVisited[u] = true;

    for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
    {
        int v = neighbors[u][i]->v;

        if (!isVisited[v])
        {
            if (containsCycle(v, u, isVisited))
                return true;
        }
        else if (v != parent)
        {
            return true;
        }
    }

    return false;
}

template<typename V>
std::vector<int> Graph<V>::getACycle() const
{
    std::vector<bool> isVisited(getSize(), false);
    std::vector<int> parent(getSize(), -1);
    std::vector<int> cycle;

    for (int i = 0; i < getSize(); i++)
    {
        if (!isVisited[i] && findCycle(i, -1, isVisited, parent, cycle))
            return cycle;
    }

    return cycle;
}

template<typename V>
bool Graph<V>::findCycle(int u, int parent, std::vector<bool>& isVisited, std::vector<int>& parentVector, std::vector<int>& cycle) const
{
    isVisited[u] = true;

    for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
    {
        int v = neighbors[u][i]->v;

        if (!isVisited[v])
        {
            parentVector[v] = u;
            if (findCycle(v, u, isVisited, parentVector, cycle))
                return true;
        }
        else if (v != parent)
        {
            cycle.push_back(v);
            int current = u;

            while (current != -1 && current != v)
            {
                cycle.push_back(current);
                current = parentVector[current];
            }

            cycle.push_back(v);
            std::reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    return false;
}

template<typename V>
bool Graph<V>::isBipartite() const
{
    std::vector<int> color(getSize(), -1);

    for (int start = 0; start < getSize(); start++)
    {
        if (color[start] != -1)
            continue;

        std::queue<int> queue;
        queue.push(start);
        color[start] = 0;

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();

            for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            {
                int v = neighbors[u][i]->v;

                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    queue.push(v);
                }
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

template<typename V>
std::vector<std::vector<int> > Graph<V>::getBipartiteSets() const
{
    std::vector<std::vector<int> > sets;
    sets.push_back(std::vector<int>());
    sets.push_back(std::vector<int>());

    std::vector<int> color(getSize(), -1);

    for (int start = 0; start < getSize(); start++)
    {
        if (color[start] != -1)
            continue;

        std::queue<int> queue;
        queue.push(start);
        color[start] = 0;

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();

            for (int i = 0; i < static_cast<int>(neighbors[u].size()); i++)
            {
                int v = neighbors[u][i]->v;

                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    queue.push(v);
                }
                else if (color[v] == color[u])
                {
                    sets.clear();
                    return sets;
                }
            }
        }
    }

    for (int i = 0; i < getSize(); i++)
        sets[color[i]].push_back(i);

    return sets;
}

#endif

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include "MST.h"
#include "ShortestPathTree.h"
#include "WeightedEdge.h"
#include <algorithm>
#include <iostream>
#include <vector>

const double WEIGHTED_INFINITY = 1.0E20;

template<typename V>
class WeightedGraph : public Graph<V>
{
public:
    WeightedGraph();
    WeightedGraph(std::vector<V>& vertices, std::vector<WeightedEdge>& edges);
    WeightedGraph(int numberOfVertices, std::vector<WeightedEdge>& edges);

    bool addEdge(int u, int v, double weight);
    void printWeightedEdges() const;
    std::vector<WeightedEdge> getWeightedEdges() const;
    std::vector<std::vector<double> > getAdjacencyMatrix() const;
    double getWeight(int u, int v) const;
    MST getMinimumSpanningTree();
    MST getMinimumSpanningTree(int startingVertex);
    MST getMinimumSpanningTreeUsingMatrix(int startingVertex);
    MST getMinimumSpanningTreeAlternative(int startingVertex);
    MST getMinimumSpanningTreeByKruskal();
    ShortestPathTree getShortestPath(int sourceVertex);
    ShortestPathTree getShortestPathUsingMatrix(int sourceVertex);
    ShortestPathTree getShortestPathAlternative(int sourceVertex);
    std::vector<int> getShortestHamiltonianCycle();
    double getPathWeight(const std::vector<int>& path) const;

private:
    MST buildTreeFromSelectedEdges(const std::vector<WeightedEdge>& selected, double totalWeight) const;
    void hamiltonianSearch(int current, std::vector<bool>& visited, std::vector<int>& path, double cost, std::vector<int>& bestPath, double& bestCost) const;
};

template<typename V>
WeightedGraph<V>::WeightedGraph()
{
}

template<typename V>
WeightedGraph<V>::WeightedGraph(std::vector<V>& vertices, std::vector<WeightedEdge>& edges)
{
    for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        this->addVertex(vertices[i]);

    for (int i = 0; i < static_cast<int>(edges.size()); i++)
        addEdge(edges[i].u, edges[i].v, edges[i].weight);
}

template<typename V>
WeightedGraph<V>::WeightedGraph(int numberOfVertices, std::vector<WeightedEdge>& edges)
{
    for (int i = 0; i < numberOfVertices; i++)
        this->addVertex(i);

    for (int i = 0; i < static_cast<int>(edges.size()); i++)
        addEdge(edges[i].u, edges[i].v, edges[i].weight);
}

template<typename V>
bool WeightedGraph<V>::addEdge(int u, int v, double weight)
{
    return this->createEdge(new WeightedEdge(u, v, weight));
}

template<typename V>
void WeightedGraph<V>::printWeightedEdges() const
{
    for (int i = 0; i < this->getSize(); i++)
    {
        std::cout << "Vertex " << this->getVertex(i) << "(" << i << "): ";

        for (int j = 0; j < static_cast<int>(this->neighbors[i].size()); j++)
        {
            WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[i][j]);
            std::cout << "(" << edge->u << ", " << edge->v << ", " << edge->weight << ") ";
        }

        std::cout << std::endl;
    }
}

template<typename V>
std::vector<WeightedEdge> WeightedGraph<V>::getWeightedEdges() const
{
    std::vector<WeightedEdge> result;

    for (int u = 0; u < static_cast<int>(this->neighbors.size()); u++)
    {
        for (int i = 0; i < static_cast<int>(this->neighbors[u].size()); i++)
        {
            WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[u][i]);
            result.push_back(*edge);
        }
    }

    return result;
}

template<typename V>
std::vector<std::vector<double> > WeightedGraph<V>::getAdjacencyMatrix() const
{
    std::vector<std::vector<double> > matrix(this->getSize());

    for (int i = 0; i < this->getSize(); i++)
    {
        matrix[i] = std::vector<double>(this->getSize(), WEIGHTED_INFINITY);
        matrix[i][i] = 0;
    }

    for (int u = 0; u < this->getSize(); u++)
    {
        for (int i = 0; i < static_cast<int>(this->neighbors[u].size()); i++)
        {
            WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[u][i]);
            matrix[edge->u][edge->v] = edge->weight;
        }
    }

    return matrix;
}

template<typename V>
double WeightedGraph<V>::getWeight(int u, int v) const
{
    for (int i = 0; i < static_cast<int>(this->neighbors[u].size()); i++)
    {
        WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[u][i]);
        if (edge->v == v)
            return edge->weight;
    }

    return WEIGHTED_INFINITY;
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree()
{
    return getMinimumSpanningTree(0);
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree(int startingVertex)
{
    int n = this->getSize();
    std::vector<bool> isInT(n, false);
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<int> searchOrders;
    double totalWeight = 0;

    cost[startingVertex] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        double currentMinCost = WEIGHTED_INFINITY;

        for (int i = 0; i < n; i++)
        {
            if (!isInT[i] && cost[i] < currentMinCost)
            {
                currentMinCost = cost[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        isInT[u] = true;
        searchOrders.push_back(u);
        totalWeight += cost[u];

        for (int i = 0; i < static_cast<int>(this->neighbors[u].size()); i++)
        {
            WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[u][i]);
            int v = edge->v;

            if (!isInT[v] && edge->weight < cost[v])
            {
                cost[v] = edge->weight;
                parent[v] = u;
            }
        }
    }

    return MST(startingVertex, parent, searchOrders, totalWeight);
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTreeUsingMatrix(int startingVertex)
{
    int n = this->getSize();
    std::vector<std::vector<double> > matrix = getAdjacencyMatrix();
    std::vector<bool> isInT(n, false);
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<int> searchOrders;
    double totalWeight = 0;

    cost[startingVertex] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        double currentMinCost = WEIGHTED_INFINITY;

        for (int i = 0; i < n; i++)
        {
            if (!isInT[i] && cost[i] < currentMinCost)
            {
                currentMinCost = cost[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        isInT[u] = true;
        searchOrders.push_back(u);
        totalWeight += cost[u];

        for (int v = 0; v < n; v++)
        {
            if (!isInT[v] && matrix[u][v] < cost[v])
            {
                cost[v] = matrix[u][v];
                parent[v] = u;
            }
        }
    }

    return MST(startingVertex, parent, searchOrders, totalWeight);
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTreeAlternative(int startingVertex)
{
    int n = this->getSize();
    std::vector<std::vector<double> > matrix = getAdjacencyMatrix();
    std::vector<bool> isInT(n, false);
    std::vector<int> parent(n, -1);
    std::vector<int> searchOrders;
    double totalWeight = 0;

    isInT[startingVertex] = true;
    searchOrders.push_back(startingVertex);

    while (static_cast<int>(searchOrders.size()) < n)
    {
        int nextU = -1;
        int nextV = -1;
        double bestWeight = WEIGHTED_INFINITY;

        for (int u = 0; u < n; u++)
        {
            if (!isInT[u])
                continue;

            for (int v = 0; v < n; v++)
            {
                if (!isInT[v] && matrix[u][v] < bestWeight)
                {
                    bestWeight = matrix[u][v];
                    nextU = u;
                    nextV = v;
                }
            }
        }

        if (nextV == -1)
            break;

        isInT[nextV] = true;
        parent[nextV] = nextU;
        searchOrders.push_back(nextV);
        totalWeight += bestWeight;
    }

    return MST(startingVertex, parent, searchOrders, totalWeight);
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTreeByKruskal()
{
    std::vector<WeightedEdge> edges = getWeightedEdges();
    std::sort(edges.begin(), edges.end());

    int n = this->getSize();
    std::vector<int> setParent(n);
    std::vector<WeightedEdge> selected;
    double totalWeight = 0;

    for (int i = 0; i < n; i++)
        setParent[i] = i;

    for (int i = 0; i < static_cast<int>(edges.size()) && static_cast<int>(selected.size()) < n - 1; i++)
    {
        int root1 = edges[i].u;
        while (setParent[root1] != root1)
            root1 = setParent[root1];

        int root2 = edges[i].v;
        while (setParent[root2] != root2)
            root2 = setParent[root2];

        if (root1 != root2)
        {
            selected.push_back(edges[i]);
            totalWeight += edges[i].weight;
            setParent[root2] = root1;
        }
    }

    return buildTreeFromSelectedEdges(selected, totalWeight);
}

template<typename V>
MST WeightedGraph<V>::buildTreeFromSelectedEdges(const std::vector<WeightedEdge>& selected, double totalWeight) const
{
    int n = this->getSize();
    std::vector<std::vector<int> > tree(n);

    for (int i = 0; i < static_cast<int>(selected.size()); i++)
    {
        tree[selected[i].u].push_back(selected[i].v);
        tree[selected[i].v].push_back(selected[i].u);
    }

    std::vector<int> parent(n, -1);
    std::vector<int> searchOrders;
    std::vector<bool> visited(n, false);
    std::vector<int> queue;
    int index = 0;

    queue.push_back(0);
    visited[0] = true;

    while (index < static_cast<int>(queue.size()))
    {
        int u = queue[index++];
        searchOrders.push_back(u);

        for (int i = 0; i < static_cast<int>(tree[u].size()); i++)
        {
            int v = tree[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                queue.push_back(v);
            }
        }
    }

    return MST(0, parent, searchOrders, totalWeight);
}

template<typename V>
ShortestPathTree WeightedGraph<V>::getShortestPath(int sourceVertex)
{
    int n = this->getSize();
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<bool> isInT(n, false);
    std::vector<int> searchOrders;

    cost[sourceVertex] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        double currentMinCost = WEIGHTED_INFINITY;

        for (int i = 0; i < n; i++)
        {
            if (!isInT[i] && cost[i] < currentMinCost)
            {
                currentMinCost = cost[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        isInT[u] = true;
        searchOrders.push_back(u);

        for (int i = 0; i < static_cast<int>(this->neighbors[u].size()); i++)
        {
            WeightedEdge* edge = static_cast<WeightedEdge*>(this->neighbors[u][i]);
            int v = edge->v;

            if (!isInT[v] && cost[u] + edge->weight < cost[v])
            {
                cost[v] = cost[u] + edge->weight;
                parent[v] = u;
            }
        }
    }

    return ShortestPathTree(sourceVertex, parent, searchOrders, cost);
}

template<typename V>
ShortestPathTree WeightedGraph<V>::getShortestPathUsingMatrix(int sourceVertex)
{
    int n = this->getSize();
    std::vector<std::vector<double> > matrix = getAdjacencyMatrix();
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<bool> isInT(n, false);
    std::vector<int> searchOrders;

    cost[sourceVertex] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        double currentMinCost = WEIGHTED_INFINITY;

        for (int i = 0; i < n; i++)
        {
            if (!isInT[i] && cost[i] < currentMinCost)
            {
                currentMinCost = cost[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        isInT[u] = true;
        searchOrders.push_back(u);

        for (int v = 0; v < n; v++)
        {
            if (!isInT[v] && matrix[u][v] < WEIGHTED_INFINITY && cost[u] + matrix[u][v] < cost[v])
            {
                cost[v] = cost[u] + matrix[u][v];
                parent[v] = u;
            }
        }
    }

    return ShortestPathTree(sourceVertex, parent, searchOrders, cost);
}

template<typename V>
ShortestPathTree WeightedGraph<V>::getShortestPathAlternative(int sourceVertex)
{
    int n = this->getSize();
    std::vector<std::vector<double> > matrix = getAdjacencyMatrix();
    std::vector<double> cost(n, WEIGHTED_INFINITY);
    std::vector<int> parent(n, -1);
    std::vector<bool> isInT(n, false);
    std::vector<int> searchOrders;

    cost[sourceVertex] = 0;
    isInT[sourceVertex] = true;
    searchOrders.push_back(sourceVertex);

    while (static_cast<int>(searchOrders.size()) < n)
    {
        int nextU = -1;
        int nextV = -1;
        double bestCost = WEIGHTED_INFINITY;

        for (int u = 0; u < n; u++)
        {
            if (!isInT[u])
                continue;

            for (int v = 0; v < n; v++)
            {
                if (!isInT[v] && matrix[u][v] < WEIGHTED_INFINITY && cost[u] + matrix[u][v] < bestCost)
                {
                    bestCost = cost[u] + matrix[u][v];
                    nextU = u;
                    nextV = v;
                }
            }
        }

        if (nextV == -1)
            break;

        isInT[nextV] = true;
        parent[nextV] = nextU;
        cost[nextV] = bestCost;
        searchOrders.push_back(nextV);
    }

    return ShortestPathTree(sourceVertex, parent, searchOrders, cost);
}

template<typename V>
std::vector<int> WeightedGraph<V>::getShortestHamiltonianCycle()
{
    std::vector<bool> visited(this->getSize(), false);
    std::vector<int> path;
    std::vector<int> bestPath;
    double bestCost = WEIGHTED_INFINITY;

    if (this->getSize() == 0)
        return bestPath;

    visited[0] = true;
    path.push_back(0);
    hamiltonianSearch(0, visited, path, 0, bestPath, bestCost);

    return bestPath;
}

template<typename V>
void WeightedGraph<V>::hamiltonianSearch(int current, std::vector<bool>& visited, std::vector<int>& path, double cost, std::vector<int>& bestPath, double& bestCost) const
{
    if (static_cast<int>(path.size()) == this->getSize())
    {
        double backWeight = getWeight(current, 0);
        if (backWeight < WEIGHTED_INFINITY && cost + backWeight < bestCost)
        {
            bestCost = cost + backWeight;
            bestPath = path;
            bestPath.push_back(0);
        }

        return;
    }

    for (int v = 0; v < this->getSize(); v++)
    {
        double weight = getWeight(current, v);

        if (!visited[v] && weight < WEIGHTED_INFINITY && cost + weight < bestCost)
        {
            visited[v] = true;
            path.push_back(v);
            hamiltonianSearch(v, visited, path, cost + weight, bestPath, bestCost);
            path.pop_back();
            visited[v] = false;
        }
    }
}

template<typename V>
double WeightedGraph<V>::getPathWeight(const std::vector<int>& path) const
{
    double result = 0;

    for (int i = 1; i < static_cast<int>(path.size()); i++)
    {
        double weight = getWeight(path[i - 1], path[i]);
        if (weight == WEIGHTED_INFINITY)
            return WEIGHTED_INFINITY;
        result += weight;
    }

    return result;
}

#endif

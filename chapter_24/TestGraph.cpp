#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Edge.h"

int main()
{
    // Vertices for graph
    std::string vertices[] = {
        "Seattle",
        "San Francisco",
        "Los Angeles",
        "Denver",
        "Kansas City",
        "Chicago",
        "Boston",
        "New York",
        "Atlanta",
        "Miami",
        "Dallas",
        "Houston"};

    int edges[][2] = {
        {0, 1}, {0, 3}, {0, 5}, {1, 0}, {1, 2}, {1, 3}, {2, 1}, {2, 3}, {2, 4}, {2, 10}, {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {4, 2}, {4, 3}, {4, 5}, {4, 7}, {4, 8}, {4, 10}, {5, 0}, {5, 3}, {5, 4}, {5, 6}, {5, 7}, {6, 5}, {6, 7}, {7, 4}, {7, 5}, {7, 6}, {7, 8}, {8, 4}, {8, 7}, {8, 9}, {8, 10}, {8, 11}, {9, 8}, {9, 11}, {10, 2}, {10, 4}, {10, 8}, {10, 11}, {11, 8}, {11, 9}, {11, 10}};

    const int NUMBER_OF_EDGES = 46;

    std::vector<std::string> vectorOfVertices(12);
    std::copy(vertices, vertices + 12, vectorOfVertices.begin());

    Graph<std::string> graph1(vectorOfVertices, edges, NUMBER_OF_EDGES);
    std::cout << "The number of vertices in graph1: " << graph1.getSize();
    std::cout << "\nThe vertex with index 1 is " << graph1.getVertex(1);
    std::cout << "\nThe index for Miami is " << graph1.getIndex("Miami");

    std::cout << "\nedges for graph1: " << std::endl;
    graph1.printEdges();

    std::cout << "\nAdjacency matrix for graph1: " << std::endl;
    graph1.printAdjacencyMatrix();

    // vector of Edge objects for graph in Figure 24.3a
    std::vector<Edge> edgeVector;
    edgeVector.push_back(Edge(0, 2));
    edgeVector.push_back(Edge(1, 2));
    edgeVector.push_back(Edge(2, 4));
    edgeVector.push_back(Edge(3, 4));

    Graph<int> graph2(5, edgeVector);

    std::cout << "The number of vertices in graph2: " << graph2.getSize();
    std::cout << "\nedges for graph2: " << std::endl;
    graph2.printEdges();

    std::cout << "\nAdjacency matrix for graph2: " << std::endl;
    graph2.printAdjacencyMatrix();

    return 0;
}
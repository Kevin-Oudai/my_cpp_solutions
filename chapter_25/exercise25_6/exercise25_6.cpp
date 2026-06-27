#include "../WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    std::vector<WeightedEdge> edges;
    edges.push_back(WeightedEdge(0, 1, 2));
    edges.push_back(WeightedEdge(1, 0, 2));
    edges.push_back(WeightedEdge(0, 2, 9));
    edges.push_back(WeightedEdge(2, 0, 9));
    edges.push_back(WeightedEdge(0, 3, 10));
    edges.push_back(WeightedEdge(3, 0, 10));
    edges.push_back(WeightedEdge(1, 2, 6));
    edges.push_back(WeightedEdge(2, 1, 6));
    edges.push_back(WeightedEdge(1, 3, 4));
    edges.push_back(WeightedEdge(3, 1, 4));
    edges.push_back(WeightedEdge(2, 3, 8));
    edges.push_back(WeightedEdge(3, 2, 8));

    WeightedGraph<int> graph(4, edges);
    std::vector<int> cycle = graph.getShortestHamiltonianCycle();

    std::cout << "Shortest Hamiltonian cycle: ";
    printPath(cycle);
    std::cout << "Cycle weight: " << graph.getPathWeight(cycle) << std::endl;

    return 0;
}

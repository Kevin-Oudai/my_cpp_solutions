#include "../WeightedGraphFileUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    int u;
    int v;

    std::cout << "Enter a file name: ";
    if (!(std::cin >> fileName))
        fileName = "Exercise25_12.txt";

    std::cout << "Enter two vertices (integer indexes): ";
    if (!(std::cin >> u >> v))
    {
        u = 0;
        v = 1;
        std::cout << u << " " << v << std::endl;
    }

    WeightedGraph<int> graph = readWeightedGraphFromFile(fileName);
    ShortestPathTree tree = graph.getShortestPath(u);

    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printWeightedEdges();
    std::cout << "A path from " << u << " to " << v << ": ";
    printPath(tree.getPath(v));

    return 0;
}

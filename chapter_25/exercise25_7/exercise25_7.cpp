#include "../WeightedGraphFileUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a file name: ";

    if (!(std::cin >> fileName))
        fileName = "Exercise25_7.txt";

    WeightedGraph<int> graph = readWeightedGraphFromFile(fileName);
    MST tree = graph.getMinimumSpanningTree();

    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printWeightedEdges();
    std::cout << "Total weight is " << tree.getTotalWeight() << std::endl;
    tree.printTree();

    return 0;
}

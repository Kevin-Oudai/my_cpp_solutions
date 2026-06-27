#include "../GraphFileUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    std::cout << "Enter a file name: ";

    if (!(std::cin >> fileName))
        fileName = "Exercise24_1a.txt";

    Graph<int> graph = readGraphFromFile(fileName);
    Tree tree = graph.dfs(0);

    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printEdges();

    if (tree.getNumberOfVerticesFound() == graph.getSize())
        std::cout << "The graph is connected" << std::endl;
    else
        std::cout << "The graph is not connected" << std::endl;

    return 0;
}

#include "../GraphFileUtilities.h"
#include <iostream>
#include <string>

int main()
{
    std::string fileName;
    int u;
    int v;

    std::cout << "Enter a file name: ";
    if (!(std::cin >> fileName))
        fileName = "Exercise24_3a.txt";

    std::cout << "Enter two vertices (integer indexes): ";
    if (!(std::cin >> u >> v))
    {
        u = 0;
        v = 5;
        std::cout << u << " " << v << std::endl;
    }

    Graph<int> graph = readGraphFromFile(fileName);
    std::vector<int> path = graph.getPath(u, v);

    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printEdges();
    std::cout << "The path is ";
    printPath(path);

    return 0;
}

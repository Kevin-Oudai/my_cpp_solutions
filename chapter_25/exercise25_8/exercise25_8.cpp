#include "../WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    writeExercise25_8File("Exercise25_8.txt");
    WeightedGraph<int> graph = readWeightedGraphFromFile("Exercise25_8.txt");

    std::cout << "Created Exercise25_8.txt" << std::endl;
    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printWeightedEdges();

    return 0;
}

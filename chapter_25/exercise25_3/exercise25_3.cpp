#include "../WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    WeightedGraph<int> graph = createExercise25SampleGraph();
    ShortestPathTree tree = graph.getShortestPathUsingMatrix(0);

    std::cout << "Shortest path from 0 to 1: ";
    printPath(tree.getPath(1));
    std::cout << "Cost: " << tree.getCost(1) << std::endl;

    return 0;
}

#include "../WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    WeightedGraph<int> graph = createExercise25SampleGraph();
    MST tree = graph.getMinimumSpanningTree(0);
    ShortestPathTree paths = graph.getShortestPath(5);

    std::cout << "The spanning tree weight is " << tree.getTotalWeight() << std::endl;
    tree.printTree();
    std::cout << "Shortest paths from 5:" << std::endl;
    paths.printAllPaths();

    return 0;
}

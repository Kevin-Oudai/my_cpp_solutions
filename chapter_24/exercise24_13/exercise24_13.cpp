#include "../GraphAlgorithms.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {1, 0}, {0, 2}, {2, 0}, {1, 2}, {2, 1},
        {2, 3}, {3, 2}, {3, 4}, {4, 3}
    };

    Graph<int> graph(5, edges, 10);
    Graph<int> subgraph = maxInducedSubgraph<int>(graph, 2);

    std::cout << "Maximum induced subgraph with degree >= 2 has " << subgraph.getSize() << " vertices" << std::endl;
    subgraph.printEdges();

    return 0;
}

#include "../Graph.h"
#include <iostream>

int main()
{
    int bipartiteEdges[][2] = {
        {0, 1}, {1, 0}, {0, 3}, {3, 0}, {2, 1}, {1, 2}, {2, 3}, {3, 2}
    };
    int nonBipartiteEdges[][2] = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 0}, {0, 2}
    };

    Graph<int> bipartiteGraph(4, bipartiteEdges, 8);
    Graph<int> nonBipartiteGraph(3, nonBipartiteEdges, 6);

    std::cout << "First graph is bipartite: " << (bipartiteGraph.isBipartite() ? "true" : "false") << std::endl;
    std::cout << "Second graph is bipartite: " << (nonBipartiteGraph.isBipartite() ? "true" : "false") << std::endl;

    return 0;
}

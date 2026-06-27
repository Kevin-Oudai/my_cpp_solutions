#include "../GraphFileUtilities.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {1, 0}, {0, 3}, {3, 0}, {2, 1}, {1, 2}, {2, 3}, {3, 2}
    };

    Graph<int> graph(4, edges, 8);
    std::vector<std::vector<int> > sets = graph.getBipartiteSets();

    if (sets.empty())
    {
        std::cout << "The graph is not bipartite" << std::endl;
    }
    else
    {
        std::cout << "Set 1: ";
        printPath(sets[0]);
        std::cout << "Set 2: ";
        printPath(sets[1]);
    }

    return 0;
}

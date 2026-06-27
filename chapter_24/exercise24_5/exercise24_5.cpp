#include "../GraphFileUtilities.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}, {3, 4}, {4, 3}
    };

    Graph<int> graph(6, edges, 6);
    std::vector<std::vector<int> > components = graph.getConnectedComponents();

    for (int i = 0; i < static_cast<int>(components.size()); i++)
    {
        std::cout << "Component " << i + 1 << ": ";
        printPath(components[i]);
    }

    return 0;
}

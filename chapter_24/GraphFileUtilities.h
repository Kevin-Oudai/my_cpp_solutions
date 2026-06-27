#ifndef GRAPHFILEUTILITIES_H
#define GRAPHFILEUTILITIES_H

#include "Graph.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline Graph<int> readGraphFromFile(const std::string& fileName)
{
    std::ifstream input(fileName.c_str());
    int numberOfVertices = 0;
    std::vector<Edge> edges;

    if (!input)
        return Graph<int>();

    input >> numberOfVertices;
    std::string line;
    std::getline(input, line);

    while (std::getline(input, line))
    {
        for (int i = 0; i < static_cast<int>(line.length()); i++)
        {
            if (line[i] == ':' || line[i] == ',')
                line[i] = ' ';
        }

        std::stringstream stream(line);
        int u;
        stream >> u;

        int v;
        while (stream >> v)
            edges.push_back(Edge(u, v));
    }

    return Graph<int>(numberOfVertices, edges);
}

inline void printPath(const std::vector<int>& path)
{
    for (int i = 0; i < static_cast<int>(path.size()); i++)
        std::cout << path[i] << " ";
    std::cout << std::endl;
}

inline void writeExercise24_2File(const std::string& fileName)
{
    int edges[][2] = {
        {0, 1}, {0, 3}, {0, 5}, {1, 0}, {1, 2}, {1, 3}, {2, 1}, {2, 3}, {2, 4}, {2, 10},
        {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {4, 2}, {4, 3}, {4, 5}, {4, 7}, {4, 8}, {4, 10},
        {5, 0}, {5, 3}, {5, 4}, {5, 6}, {5, 7}, {6, 5}, {6, 7}, {7, 4}, {7, 5}, {7, 6}, {7, 8},
        {8, 4}, {8, 7}, {8, 9}, {8, 10}, {8, 11}, {9, 8}, {9, 11}, {10, 2}, {10, 4}, {10, 8}, {10, 11},
        {11, 8}, {11, 9}, {11, 10}
    };

    std::ofstream output(fileName.c_str());
    output << 12 << std::endl;

    for (int u = 0; u < 12; u++)
    {
        output << u << ": ";
        bool first = true;

        for (int i = 0; i < 46; i++)
        {
            if (edges[i][0] == u)
            {
                if (!first)
                    output << ", ";
                output << edges[i][1];
                first = false;
            }
        }

        output << std::endl;
    }
}

#endif

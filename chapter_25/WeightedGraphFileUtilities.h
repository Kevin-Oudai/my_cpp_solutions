#ifndef WEIGHTEDGRAPHFILEUTILITIES_H
#define WEIGHTEDGRAPHFILEUTILITIES_H

#include "WeightedGraph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline WeightedGraph<int> readWeightedGraphFromFile(const std::string& fileName)
{
    std::ifstream input(fileName.c_str());
    int numberOfVertices = 0;
    std::vector<WeightedEdge> edges;

    if (!input)
        return WeightedGraph<int>();

    input >> numberOfVertices;
    std::string line;
    std::getline(input, line);

    while (std::getline(input, line))
    {
        std::stringstream lineStream(line);
        std::string segment;

        while (std::getline(lineStream, segment, '|'))
        {
            for (int i = 0; i < static_cast<int>(segment.length()); i++)
            {
                if (segment[i] == ',')
                    segment[i] = ' ';
            }

            std::stringstream edgeStream(segment);
            int u;
            int v;
            double weight;

            if (edgeStream >> u >> v >> weight)
            {
                edges.push_back(WeightedEdge(u, v, weight));
                edges.push_back(WeightedEdge(v, u, weight));
            }
        }
    }

    return WeightedGraph<int>(numberOfVertices, edges);
}

inline WeightedGraph<int> createExercise25SampleGraph()
{
    std::vector<WeightedEdge> edges;
    edges.push_back(WeightedEdge(0, 1, 100));
    edges.push_back(WeightedEdge(1, 0, 100));
    edges.push_back(WeightedEdge(0, 2, 3));
    edges.push_back(WeightedEdge(2, 0, 3));
    edges.push_back(WeightedEdge(1, 3, 20));
    edges.push_back(WeightedEdge(3, 1, 20));
    edges.push_back(WeightedEdge(2, 3, 40));
    edges.push_back(WeightedEdge(3, 2, 40));
    edges.push_back(WeightedEdge(2, 4, 2));
    edges.push_back(WeightedEdge(4, 2, 2));
    edges.push_back(WeightedEdge(3, 4, 5));
    edges.push_back(WeightedEdge(4, 3, 5));
    edges.push_back(WeightedEdge(3, 5, 5));
    edges.push_back(WeightedEdge(5, 3, 5));
    edges.push_back(WeightedEdge(4, 5, 9));
    edges.push_back(WeightedEdge(5, 4, 9));

    return WeightedGraph<int>(6, edges);
}

inline void printPath(const std::vector<int>& path)
{
    for (int i = 0; i < static_cast<int>(path.size()); i++)
        std::cout << path[i] << " ";
    std::cout << std::endl;
}

inline void writeExercise25_8File(const std::string& fileName)
{
    std::ofstream output(fileName.c_str());
    output << "12\n";
    output << "0, 1, 807 | 0, 3, 1331 | 0, 5, 2097\n";
    output << "1, 2, 381 | 1, 3, 1267\n";
    output << "2, 3, 1015 | 2, 4, 1663 | 2, 10, 1435\n";
    output << "3, 4, 599 | 3, 5, 1003\n";
    output << "4, 5, 533 | 4, 7, 1260 | 4, 8, 864 | 4, 10, 496\n";
    output << "5, 6, 983 | 5, 7, 787\n";
    output << "6, 7, 214\n";
    output << "7, 8, 888\n";
    output << "8, 9, 661 | 8, 10, 781 | 8, 11, 810\n";
    output << "9, 11, 1187\n";
    output << "10, 11, 239\n";
}

#endif

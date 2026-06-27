#ifndef TAILMODELS_H
#define TAILMODELS_H

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

class TailModel
{
public:
    TailModel(int size, bool includeDiagonals)
    {
        this->size = size;
        this->includeDiagonals = includeDiagonals;
        numberOfCells = size * size;
        numberOfNodes = 1 << numberOfCells;
        target = numberOfNodes - 1;
        buildTree();
    }

    int getNumberOfNodes() const
    {
        return numberOfNodes;
    }

    int getTarget() const
    {
        return target;
    }

    std::vector<int> getShortestPath(int node) const
    {
        std::vector<int> path;

        while (node != -1)
        {
            path.push_back(node);

            if (node == target)
                break;

            node = parent[node];
        }

        return path;
    }

    void printNode(int node) const
    {
        for (int i = 0; i < numberOfCells; i++)
            std::cout << (((node & (1 << i)) == 0) ? 'H' : 'T');
    }

    bool saveParents(const std::string& fileName) const
    {
        std::ofstream output(fileName.c_str(), std::ios::binary);
        if (!output)
            return false;

        int count = static_cast<int>(parent.size());
        output.write(reinterpret_cast<const char*>(&size), sizeof(size));
        output.write(reinterpret_cast<const char*>(&count), sizeof(count));
        output.write(reinterpret_cast<const char*>(&parent[0]), sizeof(int) * count);
        return true;
    }

private:
    int size;
    int numberOfCells;
    int numberOfNodes;
    int target;
    bool includeDiagonals;
    std::vector<int> parent;

    void buildTree()
    {
        parent.assign(numberOfNodes, -1);
        std::queue<int> queue;
        queue.push(target);
        parent[target] = target;

        while (!queue.empty())
        {
            int node = queue.front();
            queue.pop();

            for (int position = 0; position < numberOfCells; position++)
            {
                int next = getFlippedNode(node, position);
                if (parent[next] == -1)
                {
                    parent[next] = node;
                    queue.push(next);
                }
            }
        }

        parent[target] = -1;
    }

    int getFlippedNode(int node, int position) const
    {
        int row = position / size;
        int column = position % size;
        int result = node;

        for (int dr = -1; dr <= 1; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                if (!includeDiagonals && dr != 0 && dc != 0)
                    continue;

                int r = row + dr;
                int c = column + dc;

                if (r >= 0 && r < size && c >= 0 && c < size)
                    result ^= 1 << (r * size + c);
            }
        }

        return result;
    }
};

#endif

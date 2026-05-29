#include "ExecutionCounter.h"
#include <fstream>
#include <iostream>

ExecutionCounter::ExecutionCounter(const char *filename)
{
    this->filename = filename;
}

int ExecutionCounter::run() const
{
    int count = readCount();
    count++;
    writeCount(count);

    std::cout << "This program has been executed "
              << count << " time(s)." << std::endl;
    return 0;
}

int ExecutionCounter::readCount() const
{
    std::ifstream input(filename, std::ios::binary);
    int count = 0;

    if (!input.fail())
    {
        input.read((char *)&count, sizeof(int));
        input.close();
    }

    return count;
}

void ExecutionCounter::writeCount(int count) const
{
    std::ofstream output(filename, std::ios::binary);
    output.write((char *)&count, sizeof(int));
    output.close();
}

#include "ExternalSortTimer.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

namespace
{
int partition(int list[], int first, int last)
{
    int pivot = list[first];
    int low = first + 1;
    int high = last;

    while (high > low)
    {
        while (low <= high && list[low] <= pivot)
            low++;

        while (low <= high && list[high] > pivot)
            high--;

        if (high > low)
        {
            int temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    while (high > first && list[high] >= pivot)
        high--;

    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot;
        return high;
    }

    return first;
}

void quickSortRange(int list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSortRange(list, first, pivotIndex - 1);
        quickSortRange(list, pivotIndex + 1, last);
    }
}

bool readNextInRun(std::ifstream &input, int &value, int &count, int segmentSize)
{
    if (count >= segmentSize)
        return false;

    input.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (!input)
        return false;

    count++;
    return true;
}
}

void ExternalSortTimer::run() const
{
    std::cout << "Use exercise sizes? Enter 1 for yes, 0 for quick test: ";
    int choice;
    std::cin >> choice;
    displayTable(choice == 1);
}

void ExternalSortTimer::displayTable(bool useExerciseSizes) const
{
    int exerciseSizes[6] = {5000000, 10000000, 15000000, 20000000, 25000000, 30000000};
    int quickSizes[6] = {5000, 10000, 15000, 20000, 25000, 30000};
    int* sizes = useExerciseSizes ? exerciseSizes : quickSizes;

    std::cout << std::setw(12) << "File size";
    for (int i = 0; i < 6; i++)
        std::cout << std::setw(10) << sizes[i];
    std::cout << std::endl;

    std::cout << std::setw(12) << "Time";
    for (int i = 0; i < 6; i++)
        std::cout << std::setw(10) << timeExternalSort(sizes[i]);
    std::cout << std::endl;
}

void ExternalSortTimer::createDataFile(const std::string &fileName, int size) const
{
    std::ofstream output(fileName.c_str(), std::ios::out | std::ios::binary);
    std::srand(1);

    for (int i = 0; i < size; i++)
    {
        int value = std::rand();
        output.write(reinterpret_cast<char*>(&value), sizeof(value));
    }

    output.close();
}

void ExternalSortTimer::sortFile(const std::string &sourceFile, const std::string &targetFile, int segmentSize) const
{
    int numberOfSegments = initializeSegments(segmentSize, sourceFile, "f1.dat");
    merge(numberOfSegments, segmentSize, "f1.dat", "f2.dat", "f3.dat", targetFile);
}

int ExternalSortTimer::initializeSegments(int segmentSize, const std::string &sourceFile, const std::string &f1) const
{
    int* list = new int[segmentSize];
    std::ifstream input(sourceFile.c_str(), std::ios::in | std::ios::binary);
    std::ofstream output(f1.c_str(), std::ios::out | std::ios::binary);

    int numberOfSegments = 0;
    while (input)
    {
        int count = 0;
        while (count < segmentSize && input.read(reinterpret_cast<char*>(&list[count]), sizeof(list[count])))
            count++;

        if (count == 0)
            break;

        numberOfSegments++;
        quickSort(list, count);

        for (int i = 0; i < count; i++)
            output.write(reinterpret_cast<char*>(&list[i]), sizeof(list[i]));
    }

    input.close();
    output.close();
    delete [] list;

    return numberOfSegments;
}

void ExternalSortTimer::merge(int numberOfSegments, int segmentSize, const std::string &f1,
    const std::string &f2, const std::string &f3, const std::string &targetFile) const
{
    if (numberOfSegments > 1)
    {
        mergeOneStep(numberOfSegments, segmentSize, f1, f2, f3);
        merge((numberOfSegments + 1) / 2, segmentSize * 2, f3, f1, f2, targetFile);
    }
    else
    {
        copyFile(f1, targetFile);
    }
}

void ExternalSortTimer::mergeOneStep(int numberOfSegments, int segmentSize, const std::string &f1,
    const std::string &f2, const std::string &f3) const
{
    std::ifstream f1Input(f1.c_str(), std::ios::in | std::ios::binary);
    std::ofstream f2Output(f2.c_str(), std::ios::out | std::ios::binary);
    copyHalfToF2(numberOfSegments, segmentSize, f1Input, f2Output);
    f2Output.close();

    std::ifstream f2Input(f2.c_str(), std::ios::in | std::ios::binary);
    std::ofstream f3Output(f3.c_str(), std::ios::out | std::ios::binary);
    mergeSegments(numberOfSegments / 2, segmentSize, f1Input, f2Input, f3Output);

    f1Input.close();
    f2Input.close();
    f3Output.close();
}

void ExternalSortTimer::copyHalfToF2(int numberOfSegments, int segmentSize, std::ifstream &f1,
    std::ofstream &f2) const
{
    int count = (numberOfSegments / 2) * segmentSize;
    for (int i = 0; i < count; i++)
    {
        int value;
        if (!readInt(f1, value))
            break;
        f2.write(reinterpret_cast<char*>(&value), sizeof(value));
    }
}

void ExternalSortTimer::mergeSegments(int numberOfSegments, int segmentSize, std::ifstream &f1,
    std::ifstream &f2, std::ofstream &f3) const
{
    for (int i = 0; i < numberOfSegments; i++)
        mergeTwoSegments(segmentSize, f1, f2, f3);

    copyRemaining(f1, f3);
}

void ExternalSortTimer::mergeTwoSegments(int segmentSize, std::ifstream &f1, std::ifstream &f2,
    std::ofstream &f3) const
{
    int intFromF1;
    int intFromF2;
    int f1Count = 0;
    int f2Count = 0;
    bool hasF1 = readNextInRun(f1, intFromF1, f1Count, segmentSize);
    bool hasF2 = readNextInRun(f2, intFromF2, f2Count, segmentSize);

    while (hasF1 && hasF2)
    {
        if (intFromF1 < intFromF2)
        {
            f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(intFromF1));
            hasF1 = readNextInRun(f1, intFromF1, f1Count, segmentSize);
        }
        else
        {
            f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
            hasF2 = readNextInRun(f2, intFromF2, f2Count, segmentSize);
        }
    }

    while (hasF1)
    {
        f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(intFromF1));
        hasF1 = readNextInRun(f1, intFromF1, f1Count, segmentSize);
    }

    while (hasF2)
    {
        f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(intFromF2));
        hasF2 = readNextInRun(f2, intFromF2, f2Count, segmentSize);
    }
}

void ExternalSortTimer::copyRemaining(std::ifstream &input, std::ofstream &output) const
{
    int value;
    while (readInt(input, value))
        output.write(reinterpret_cast<char*>(&value), sizeof(value));
}

void ExternalSortTimer::copyFile(const std::string &sourceFile, const std::string &targetFile) const
{
    std::ifstream input(sourceFile.c_str(), std::ios::in | std::ios::binary);
    std::ofstream output(targetFile.c_str(), std::ios::out | std::ios::binary);
    copyRemaining(input, output);
    input.close();
    output.close();
}

bool ExternalSortTimer::readInt(std::ifstream &input, int &value) const
{
    input.read(reinterpret_cast<char*>(&value), sizeof(value));
    return static_cast<bool>(input);
}

void ExternalSortTimer::quickSort(int list[], int arraySize) const
{
    quickSortRange(list, 0, arraySize - 1);
}

long ExternalSortTimer::timeExternalSort(int size) const
{
    createDataFile("largedata.dat", size);

    long startTime = static_cast<long>(time(0));
    sortFile("largedata.dat", "sortedfile.dat", 10000);
    long endTime = static_cast<long>(time(0));

    if (!isSortedFile("sortedfile.dat"))
        return -1;

    return endTime - startTime;
}

bool ExternalSortTimer::isSortedFile(const std::string &fileName) const
{
    std::ifstream input(fileName.c_str(), std::ios::in | std::ios::binary);
    int previous;
    if (!readInt(input, previous))
    {
        input.close();
        return true;
    }

    int current;
    while (readInt(input, current))
    {
        if (current < previous)
        {
            input.close();
            return false;
        }
        previous = current;
    }

    input.close();
    return true;
}

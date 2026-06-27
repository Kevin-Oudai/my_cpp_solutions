#include "SortingTimer.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace
{
class IntHeap
{
public:
    void add(int element)
    {
        values.push_back(element);
        int currentIndex = static_cast<int>(values.size()) - 1;

        while (currentIndex > 0)
        {
            int parentIndex = (currentIndex - 1) / 2;
            if (values[currentIndex] > values[parentIndex])
            {
                int temp = values[currentIndex];
                values[currentIndex] = values[parentIndex];
                values[parentIndex] = temp;
                currentIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int remove()
    {
        if (values.size() == 0)
            throw std::runtime_error("Heap is empty");

        int removedElement = values[0];
        values[0] = values[values.size() - 1];
        values.pop_back();

        int currentIndex = 0;
        while (currentIndex < static_cast<int>(values.size()))
        {
            int leftChildIndex = 2 * currentIndex + 1;
            int rightChildIndex = 2 * currentIndex + 2;

            if (leftChildIndex >= static_cast<int>(values.size()))
                break;

            int maxIndex = leftChildIndex;
            if (rightChildIndex < static_cast<int>(values.size()) &&
                values[maxIndex] < values[rightChildIndex])
                maxIndex = rightChildIndex;

            if (values[currentIndex] < values[maxIndex])
            {
                int temp = values[currentIndex];
                values[currentIndex] = values[maxIndex];
                values[maxIndex] = temp;
                currentIndex = maxIndex;
            }
            else
            {
                break;
            }
        }

        return removedElement;
    }

private:
    std::vector<int> values;
};

void mergeLists(int list1[], int list1Size, int list2[], int list2Size, int temp[])
{
    int current1 = 0;
    int current2 = 0;
    int current3 = 0;

    while (current1 < list1Size && current2 < list2Size)
    {
        if (list1[current1] < list2[current2])
            temp[current3++] = list1[current1++];
        else
            temp[current3++] = list2[current2++];
    }

    while (current1 < list1Size)
        temp[current3++] = list1[current1++];

    while (current2 < list2Size)
        temp[current3++] = list2[current2++];
}

void arraycopy(int source[], int sourceStartIndex, int target[], int targetStartIndex, int length)
{
    for (int i = 0; i < length; i++)
        target[i + targetStartIndex] = source[i + sourceStartIndex];
}

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
}

void SortingTimer::run() const
{
    std::cout << "Use exercise sizes? Enter 1 for yes, 0 for quick test: ";
    int choice;
    std::cin >> choice;
    displayTable(choice == 1);
}

void SortingTimer::displayTable(bool useExerciseSizes) const
{
    int exerciseSizes[6] = {500000, 1000000, 1500000, 2000000, 2500000, 3000000};
    int quickSizes[6] = {500, 1000, 1500, 2000, 2500, 3000};
    int* sizes = useExerciseSizes ? exerciseSizes : quickSizes;

    const char* labels[6] = {
        "Selection Sort", "Insertion Sort", "Bubble Sort",
        "Merge Sort", "Quick Sort", "Heap Sort"
    };

    std::cout << std::setw(18) << "Array size";
    for (int i = 0; i < 6; i++)
        std::cout << std::setw(10) << sizes[i];
    std::cout << std::endl;

    for (int algorithm = 0; algorithm < 6; algorithm++)
    {
        std::cout << std::setw(18) << labels[algorithm];
        for (int i = 0; i < 6; i++)
            std::cout << std::setw(10) << timeSort(algorithm, sizes[i]);
        std::cout << std::endl;
    }
}

void SortingTimer::selectionSort(int list[], int arraySize) const
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        int currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < arraySize; j++)
        {
            if (currentMin > list[j])
            {
                currentMin = list[j];
                currentMinIndex = j;
            }
        }

        if (currentMinIndex != i)
        {
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}

void SortingTimer::insertionSort(int list[], int arraySize) const
{
    for (int i = 1; i < arraySize; i++)
    {
        int currentElement = list[i];
        int k;
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
            list[k + 1] = list[k];

        list[k + 1] = currentElement;
    }
}

void SortingTimer::bubbleSort(int list[], int arraySize) const
{
    bool needNextPass = true;

    for (int k = 1; k < arraySize && needNextPass; k++)
    {
        needNextPass = false;
        for (int i = 0; i < arraySize - k; i++)
        {
            if (list[i] > list[i + 1])
            {
                int temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                needNextPass = true;
            }
        }
    }
}

void SortingTimer::mergeSort(int list[], int arraySize) const
{
    if (arraySize > 1)
    {
        int* firstHalf = new int[arraySize / 2];
        arraycopy(list, 0, firstHalf, 0, arraySize / 2);
        mergeSort(firstHalf, arraySize / 2);

        int secondHalfLength = arraySize - arraySize / 2;
        int* secondHalf = new int[secondHalfLength];
        arraycopy(list, arraySize / 2, secondHalf, 0, secondHalfLength);
        mergeSort(secondHalf, secondHalfLength);

        mergeLists(firstHalf, arraySize / 2, secondHalf, secondHalfLength, list);

        delete [] firstHalf;
        delete [] secondHalf;
    }
}

void SortingTimer::quickSort(int list[], int arraySize) const
{
    quickSortRange(list, 0, arraySize - 1);
}

void SortingTimer::heapSort(int list[], int arraySize) const
{
    IntHeap heap;

    for (int i = 0; i < arraySize; i++)
        heap.add(list[i]);

    for (int i = 0; i < arraySize; i++)
        list[arraySize - i - 1] = heap.remove();
}

long SortingTimer::timeSort(int algorithm, int size) const
{
    int* base = createRandomArray(size);
    int* list = copyArray(base, size);

    long startTime = static_cast<long>(time(0));
    if (algorithm == 0)
        selectionSort(list, size);
    else if (algorithm == 1)
        insertionSort(list, size);
    else if (algorithm == 2)
        bubbleSort(list, size);
    else if (algorithm == 3)
        mergeSort(list, size);
    else if (algorithm == 4)
        quickSort(list, size);
    else
        heapSort(list, size);
    long endTime = static_cast<long>(time(0));

    long executionTime = endTime - startTime;
    if (!isSorted(list, size))
        executionTime = -1;

    delete [] base;
    delete [] list;

    return executionTime;
}

int* SortingTimer::createRandomArray(int size) const
{
    int* list = new int[size];
    std::srand(1);
    for (int i = 0; i < size; i++)
        list[i] = std::rand();
    return list;
}

int* SortingTimer::copyArray(int source[], int size) const
{
    int* target = new int[size];
    for (int i = 0; i < size; i++)
        target[i] = source[i];
    return target;
}

bool SortingTimer::isSorted(int list[], int size) const
{
    for (int i = 1; i < size; i++)
    {
        if (list[i] < list[i - 1])
            return false;
    }

    return true;
}

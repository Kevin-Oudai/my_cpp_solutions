#ifndef MEDIANQUICKSORTER_H
#define MEDIANQUICKSORTER_H

template<typename T>
void swapElements(T list[], int firstIndex, int secondIndex)
{
    T temp = list[firstIndex];
    list[firstIndex] = list[secondIndex];
    list[secondIndex] = temp;
}

template<typename T>
int medianOfThreeIndex(T list[], int first, int middle, int last)
{
    if ((list[first] <= list[middle] && list[middle] <= list[last]) ||
        (list[last] <= list[middle] && list[middle] <= list[first]))
    {
        return middle;
    }

    if ((list[middle] <= list[first] && list[first] <= list[last]) ||
        (list[last] <= list[first] && list[first] <= list[middle]))
    {
        return first;
    }

    return last;
}

template<typename T>
int medianPartition(T list[], int first, int last)
{
    int middle = (first + last) / 2;
    int pivotIndex = medianOfThreeIndex(list, first, middle, last);
    swapElements(list, first, pivotIndex);

    T pivot = list[first];
    int low = first + 1;
    int high = last;

    while (high > low)
    {
        while (low <= high && list[low] <= pivot)
            low++;

        while (low <= high && list[high] > pivot)
            high--;

        if (high > low)
            swapElements(list, low, high);
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

template<typename T>
void medianQuickSort(T list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = medianPartition(list, first, last);
        medianQuickSort(list, first, pivotIndex - 1);
        medianQuickSort(list, pivotIndex + 1, last);
    }
}

template<typename T>
void medianQuickSort(T list[], int arraySize)
{
    medianQuickSort(list, 0, arraySize - 1);
}

class MedianQuickSorter
{
public:
    void run() const;
};

#endif

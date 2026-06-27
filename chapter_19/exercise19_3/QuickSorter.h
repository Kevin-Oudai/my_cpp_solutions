#ifndef QUICKSORTER_H
#define QUICKSORTER_H

template<typename T>
int partition(T list[], int first, int last)
{
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
        {
            T temp = list[high];
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

template<typename T>
void quickSort(T list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    }
}

template<typename T>
void quickSort(T list[], int arraySize)
{
    quickSort(list, 0, arraySize - 1);
}

class QuickSorter
{
public:
    void run() const;
};

#endif

#ifndef MERGESORTER_H
#define MERGESORTER_H

template<typename T>
void arraycopy(T source[], int sourceStartIndex, T target[], int targetStartIndex, int length)
{
    for (int i = 0; i < length; i++)
    {
        target[i + targetStartIndex] = source[i + sourceStartIndex];
    }
}

template<typename T>
void merge(T list1[], int list1Size, T list2[], int list2Size, T temp[])
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

template<typename T>
void mergeSort(T list[], int arraySize)
{
    if (arraySize > 1)
    {
        T* firstHalf = new T[arraySize / 2];
        arraycopy(list, 0, firstHalf, 0, arraySize / 2);
        mergeSort(firstHalf, arraySize / 2);

        int secondHalfLength = arraySize - arraySize / 2;
        T* secondHalf = new T[secondHalfLength];
        arraycopy(list, arraySize / 2, secondHalf, 0, secondHalfLength);
        mergeSort(secondHalf, secondHalfLength);

        merge(firstHalf, arraySize / 2, secondHalf, secondHalfLength, list);

        delete [] firstHalf;
        delete [] secondHalf;
    }
}

class MergeSorter
{
public:
    void run() const;
};

#endif

#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

template<typename T>
void bubbleSort(T list[], int arraySize)
{
    bool needNextPass = true;

    for (int k = 1; k < arraySize && needNextPass; k++)
    {
        needNextPass = false;
        for (int i = 0; i < arraySize - k; i++)
        {
            if (list[i] > list[i + 1])
            {
                T temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                needNextPass = true;
            }
        }
    }
}

class BubbleSorter
{
public:
    void run() const;
};

#endif

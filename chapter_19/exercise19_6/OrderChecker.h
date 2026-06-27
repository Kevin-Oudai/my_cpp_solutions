#ifndef ORDERCHECKER_H
#define ORDERCHECKER_H

template<typename T>
bool ordered(T list[], int size, bool ascending)
{
    for (int i = 1; i < size; i++)
    {
        if (ascending)
        {
            if (list[i] < list[i - 1])
                return false;
        }
        else
        {
            if (list[i] > list[i - 1])
                return false;
        }
    }

    return true;
}

template<typename T>
bool ordered(T list[], int size)
{
    return ordered(list, size, true);
}

class OrderChecker
{
public:
    void run() const;
};

#endif

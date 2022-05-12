// Listing 7.10 - BinarySearch.cpp
int binarySearch(const int list[], int key, int listSize)
{
    int low = 0;
    int high = listSize - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
            high = mid - 1;
        else if (key == list[mid])
            return mid;
        else
            low = mid + 1;
    }

    return -low - 1;
}
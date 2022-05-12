// Listing 7.9 - LinearSearch.cpp

int linearSearch(const int list[], int key, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (key == list[i])
        {
            return i;
        }
        return -1;
    }
}
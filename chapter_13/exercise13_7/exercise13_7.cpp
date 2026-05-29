#include "UniqueNameSorter.h"

int main()
{
    UniqueNameSorter sorter(20000, "SortedNamesWithoutDuplicates.txt");
    return sorter.run();
}

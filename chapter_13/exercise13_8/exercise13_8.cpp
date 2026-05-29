#include "DuplicateNameSorter.h"

int main()
{
    DuplicateNameSorter sorter(20000, "SortedNamesWithDuplicates.txt");
    return sorter.run();
}

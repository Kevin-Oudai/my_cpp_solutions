#include <iostream>

template <typename T>
bool areStrictlyIdentical(const T list1[], const T list2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list1[i] != list2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int integers1[] = {2, 6, 9, 10, 30, 21};
    int integers2[] = {2, 6, 9, 10, 30, 21};
    double decimals1[] = {1.2, 3.9, 2.1, 9.3, 4.5, 3.5};
    double decimals2[] = {1.25, 3.9, 2.1, 9.3, 4.5, 3.5};
    std::string strings[] = {"Kevin", "Venita", "Athena"};
    std::string strings2[] = {"Kevin", "Venita", "James"};
    std::cout << ((areStrictlyIdentical(integers1, integers2, 6)) ? "They are identical" : "They are NOT identical") << std::endl;
    std::cout << ((areStrictlyIdentical(decimals1, decimals2, 6)) ? "They are identical" : "They are NOT identical") << std::endl;
    std::cout << ((areStrictlyIdentical(strings, strings2, 3)) ? "They are identical" : "They are NOT identical") << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

template <typename T>
void addvector(std::vector<T> &v1, std::vector<T> &v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " + " << v2[i] << " = " << v1[i] + v2[i] << std::endl;
    }
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    std::cout << "Enter 6 values for v1: ";
    int value;
    for (int i = 0; i < 6; i++)
    {
        std::cin >> value;
        v1.push_back(value);
    }

    std::cout << "Enter the 6 values for v2: ";
    for (int i = 0; i < 6; i++)
    {
        std::cin >> value;
        v2.push_back(value);
    }
    addvector(v1, v2);

    return 0;
}

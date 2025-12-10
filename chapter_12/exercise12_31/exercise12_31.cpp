#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::vector<T> intersect(const std::vector<T> &v1, const std::vector<T> &v2)
{
    std::vector<T> result;
    for (const T &item : v1)
    {
        bool inSecond = false;
        for (const T &candidate : v2)
        {
            if (item == candidate)
            {
                inSecond = true;
                break;
            }
        }
        if (inSecond)
        {
            bool alreadyAdded = false;
            for (const T &existing : result)
            {
                if (existing == item)
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded)
            {
                result.push_back(item);
            }
        }
    }
    return result;
}

int main()
{
    const int COUNT = 5;
    std::vector<std::string> v1(COUNT);
    std::vector<std::string> v2(COUNT);

    std::cout << "Enter five strings for vector1:" << std::endl;
    for (int i = 0; i < COUNT; i++)
    {
        std::cin >> v1[i];
    }

    std::cout << "Enter five strings for vector2:" << std::endl;
    for (int i = 0; i < COUNT; i++)
    {
        std::cin >> v2[i];
    }

    std::vector<std::string> common = intersect(v1, v2);

    std::cout << "The common strings are";
    for (const auto &s : common)
    {
        std::cout << " " << s;
    }
    std::cout << std::endl;

    return 0;
}

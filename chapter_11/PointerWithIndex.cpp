#include <iostream>

int main()
{
    int list[6] = {11, 12, 13, 14, 15, 16};
    int *p = list;

    for (int i = 0; i < 6; i++)
    {
        std::cout << "address: " << (list + i)
                  << " value: " << *(list + i) << " "
                  << " value: " << list[i] << " "
                  << " value: " << *(p + i) << " "
                  << " value: " << p[i] << std::endl;
    }

    return 0;
}
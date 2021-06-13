// Exercise 5.41 - Occurence of Max Numbers

#include <iostream>

int main()
{
    std::cout << "Enter numbers: ";
    int num, max, count = 1;
    std::cin >> num;
    max = num;
    while (num != 0)
    {
        std::cin >> num;
        if (num > max)
        {
            max = num;
            count = 1;
        }
        else if (num == max)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    std::cout << "The largest number is " << max << std::endl;
    std::cout << "The occurrence count of the largest number is " << count << std::endl;
    return 0;
}
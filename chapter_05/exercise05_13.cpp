// Exercise 5.13 - Find numbers divisible by 3 or 6, but not both
#include <iostream>

int main()
{
    int startValue = 300;
    int endValue = 500;
    const int NUMBERS_PER_LINE = 5;
    int count = 0;
    while (startValue <= endValue)
    {
        if ((startValue % 3 == 0 && startValue % 6 != 0) || (startValue % 3 != 0 && startValue % 6 == 0))
        {
            std::cout << startValue << " ";
            count++;
            if (count % NUMBERS_PER_LINE == 0)
            {
                std::cout << std::endl;
            }
        }

        startValue++;
    }
    return 0;
}
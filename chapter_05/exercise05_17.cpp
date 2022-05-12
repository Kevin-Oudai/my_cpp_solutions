// Exercise 5.17 - Display the ASCII Character Table

#include <iostream>

int main()
{
    int startValue = 65;
    int endValue = 90;
    int count = 0;
    const int CHARACTERS_PER_LINE = 5;

    while (startValue <= endValue)
    {
        std::cout << static_cast<char>(startValue) << " ";
        count++;
        if (count % CHARACTERS_PER_LINE == 0)
        {
            std::cout << std::endl;
        }

        startValue++;
    }
    return 0;
}
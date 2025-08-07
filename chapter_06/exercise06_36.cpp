// Exercise 6.36 - Format an integer

#include <iostream>
#include <string>

std::string format(int number, int width)
{
    std::string result;
    for (int i = 0; i < width; i++)
    {
        if (number > 0)
        {
            result = static_cast<char>(((number % 10) + '0')) + result;
            number /= 10;
        }
        else
        {
            result = "0" + result;
        }
    }
    return result;
}

int main()
{
    std::string result = format(34, 4);
    std::cout << "Result: " << result << std::endl;

    result = format(34, 5);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
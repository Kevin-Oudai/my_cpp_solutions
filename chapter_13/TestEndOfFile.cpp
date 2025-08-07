#include <iostream>
#include <fstream>

int main()
{
    // Open a file
    std::ifstream input("score.txt");
    if (input.fail())
    {
        std::cout << "File does not exist" << std::endl;
        std::cout << "Exit program" << std::endl;
        return 0;
    }

    double sum = 0;
    double number;
    while (input >> number)
    {
        std::cout << number << " ";
        sum += number;
    }

    input.close();
    std::cout << "\nSum is " << sum << std::endl;

    return 0;
}
#include <iostream>
#include <string>

std::string sort(std::string &s)
{
    std::string result;
    int lowest;
    while (s.length() > 0)
    {
        lowest = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(lowest, 1) > s.substr(i, 1))
            {
                lowest = i;
            }
        }
        result.append(s.substr(lowest, 1));
        s.erase(lowest, 1);
    }
    return result;
}

int main()
{
    std::string input, output;
    std::cout << "Enter a string s: ";
    std::cin >> input;
    output = sort(input);
    std::cout << "The sorted string is " << output << std::endl;
    return 0;
}
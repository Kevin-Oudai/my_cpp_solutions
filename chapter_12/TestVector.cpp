#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> intVector;

    // Store numbers 1, 2, 3, 4, 5, ..., 10 to the vector
    for (int i = 0; i < 10; i++)
    {
        intVector.push_back(i + 1);
    }

    // Display the numbers in the vector
    std::cout << "Numbers in the vector";
    for (int i = 0; i < intVector.size(); i++)
    {
        std::cout << intVector[i] << " ";
    }

    std::vector<std::string> stringVector;

    // Store strings into the vector
    stringVector.push_back("Dallas");
    stringVector.push_back("Houston");
    stringVector.push_back("Austin");
    stringVector.push_back("Norman");

    // Display the string in the vector
    std::cout << "\nStrings in the string vector: ";
    for (int i = 0; i < stringVector.size(); i++)
    {
        std::cout << stringVector[i] << " ";
    }

    stringVector.pop_back(); // Remove the last element
    std::vector<std::string> v2;
    v2.swap(stringVector);
    v2[0] = "Atlanta";

    // Redisplay the string in the vector
    std::cout << "\nStrings in the vector v2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        std::cout << v2.at(i) << " ";
    }

    return 0;
}
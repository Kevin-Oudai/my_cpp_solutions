#include <iostream>

bool isVowel(char letter)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 10; i++)
    {
        if (vowels[i] == letter)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    typedef char *intPtr;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    intPtr values = new char[size];
    std::cout << "Enter the characters" << std::endl;
    char letter;
    int numberOfLetters = 0;
    for (int i = 0; i < size; i++)
    {
        std::cin >> letter;
        if (!isVowel(letter))
        {
            *(values + numberOfLetters) = letter;
            numberOfLetters++;
        }
    }

    for (int i = 0; i < numberOfLetters; i++)
    {
        std::cout << *(values + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
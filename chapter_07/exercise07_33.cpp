// Exercise 7.33 - Palindrome String
// Revision: Exercise 4.17 - Palindrome String
// Note: Exercise 4.17 only requires you to determine if a word of length 5 is a palindrome
// hence, this program uses the described function only to achieve the same effect with c-strings

#include <iostream>
#include <string>

int isPalindrome(const char s[])
{
    if (s[0] == s[4] && s[1] == s[3])
    {
        return strlen(s);
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::cout << "Enter a string with five lowercase letters: ";
    char word[6];
    std::cin.getline(word, 6);
    if (strlen(word) == 5)
    {
        if (isPalindrome(word) != -1)
        {
            std::cout << word << "is a palindrome" << std::endl;
        }
        else
        {
            std::cout << word << "is NOT a palindrome" << std::endl;
        }
    }
    else
    {
        std::cout << "Either you entered a word with the wrong length or the input was invalid." << std::endl;
    }

    return 0;
}
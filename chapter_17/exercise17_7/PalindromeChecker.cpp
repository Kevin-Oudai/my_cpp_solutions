#include "PalindromeChecker.h"

PalindromeChecker::PalindromeChecker()
{
    callCount = 0;
}

bool PalindromeChecker::isPalindrome(const std::string &text)
{
    callCount = 0;
    return isPalindrome(text, 0, static_cast<int>(text.length()) - 1);
}

int PalindromeChecker::getCallCount() const
{
    return callCount;
}

bool PalindromeChecker::isPalindrome(const std::string &text, int low, int high)
{
    callCount++;
    if (high <= low)
    {
        return true;
    }
    if (text[low] != text[high])
    {
        return false;
    }
    return isPalindrome(text, low + 1, high - 1);
}

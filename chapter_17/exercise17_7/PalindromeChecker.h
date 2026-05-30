#ifndef PALINDROMECHECKER_H
#define PALINDROMECHECKER_H

#include <string>

class PalindromeChecker
{
public:
    PalindromeChecker();

    bool isPalindrome(const std::string &text);
    int getCallCount() const;

private:
    int callCount;

    bool isPalindrome(const std::string &text, int low, int high);
};

#endif

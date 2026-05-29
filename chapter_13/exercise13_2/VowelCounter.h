#ifndef VOWELCOUNTER_H
#define VOWELCOUNTER_H

class VowelCounter
{
public:
    int run() const;

private:
    int countVowels(const char *filename, bool &fileExists) const;
    bool isVowel(char ch) const;
};

#endif

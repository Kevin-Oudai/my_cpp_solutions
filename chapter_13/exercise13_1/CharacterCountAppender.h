#ifndef CHARACTERCOUNTAPPENDER_H
#define CHARACTERCOUNTAPPENDER_H

class CharacterCountAppender
{
public:
    CharacterCountAppender(const char *filename);
    int run() const;

private:
    const char *filename;

    int countCharacters(bool &fileExists) const;
    void appendCount(int count) const;
};

#endif

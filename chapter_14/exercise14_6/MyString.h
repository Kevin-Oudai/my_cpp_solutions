#ifndef MYSTRING_H
#define MYSTRING_H

#include <iosfwd>

class MyString
{
public:
    MyString();
    MyString(const char s[]);
    MyString(const MyString &s);
    ~MyString();

    int getLength() const;
    const char *c_str() const;

    MyString &operator=(const MyString &secondString);
    char &operator[](int index);
    char operator[](int index) const;
    MyString operator+(const MyString &secondString) const;
    MyString &operator+=(const MyString &secondString);

    friend std::ostream &operator<<(std::ostream &output, const MyString &s);

private:
    char *chars;
    int length;

    void copy(const char s[]);
};

#endif

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
    bool operator==(const MyString &secondString) const;
    bool operator!=(const MyString &secondString) const;
    bool operator>(const MyString &secondString) const;
    bool operator>=(const MyString &secondString) const;

    friend std::istream &operator>>(std::istream &input, MyString &s);
    friend std::ostream &operator<<(std::ostream &output, const MyString &s);

private:
    char *chars;
    int length;

    void copy(const char s[]);
};

#endif

#include "MyString.h"
#include <cstring>
#include <iostream>

MyString::MyString()
{
    copy("");
}

MyString::MyString(const char s[])
{
    copy(s);
}

MyString::MyString(const MyString &s)
{
    copy(s.chars);
}

MyString::~MyString()
{
    delete[] chars;
}

int MyString::getLength() const
{
    return length;
}

const char *MyString::c_str() const
{
    return chars;
}

MyString &MyString::operator=(const MyString &secondString)
{
    if (this != &secondString)
    {
        delete[] chars;
        copy(secondString.chars);
    }
    return *this;
}

char &MyString::operator[](int index)
{
    return chars[index];
}

char MyString::operator[](int index) const
{
    return chars[index];
}

MyString MyString::operator+(const MyString &secondString) const
{
    char *combined = new char[length + secondString.length + 1];
    std::strcpy(combined, chars);
    std::strcat(combined, secondString.chars);

    MyString result(combined);
    delete[] combined;
    return result;
}

MyString &MyString::operator+=(const MyString &secondString)
{
    *this = *this + secondString;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const MyString &s)
{
    output << s.chars;
    return output;
}

void MyString::copy(const char s[])
{
    length = static_cast<int>(std::strlen(s));
    chars = new char[length + 1];
    std::strcpy(chars, s);
}

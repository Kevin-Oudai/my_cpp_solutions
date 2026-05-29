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

bool MyString::operator==(const MyString &secondString) const
{
    return std::strcmp(chars, secondString.chars) == 0;
}

bool MyString::operator!=(const MyString &secondString) const
{
    return !(*this == secondString);
}

bool MyString::operator>(const MyString &secondString) const
{
    return std::strcmp(chars, secondString.chars) > 0;
}

bool MyString::operator>=(const MyString &secondString) const
{
    return std::strcmp(chars, secondString.chars) >= 0;
}

std::istream &operator>>(std::istream &input, MyString &s)
{
    char buffer[1000];
    input >> buffer;
    s = MyString(buffer);
    return input;
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

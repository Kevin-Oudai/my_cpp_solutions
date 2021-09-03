// Exercise 7.38 - Convert Float to string

#include <iostream>
#include <cstring>

void ftoa(double f, char s[])
{
    int whole = f;
    int fraction = (f - whole + 0.0001) * 1000;
    char w[100], fr[100];
    itoa(whole, w, 10);
    itoa(fraction, fr, 10);

    strcat(s, w);
    strcat(s, ".");
    strcat(s, fr);
}

int main()
{
    double f;
    std::cout << "Enter 3 decimal place float: ";
    std::cin >> f;

    char s[100] = "";
    ftoa(f, s);
    std::cout << "s: " << s << std::endl;
    return 0;
}
#ifndef EMPTYSTACKEXCEPTION_H
#define EMPTYSTACKEXCEPTION_H

#include <stdexcept>

class EmptyStackException : public std::runtime_error
{
public:
    EmptyStackException();
};

#endif

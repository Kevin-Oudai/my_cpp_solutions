#ifndef ILLEGALSUBSCRIPTEXCEPTION_H
#define ILLEGALSUBSCRIPTEXCEPTION_H

#include <stdexcept>

class IllegalSubscriptException : public std::runtime_error
{
public:
    IllegalSubscriptException(int index);
    int getIndex() const;

private:
    int index;
};

#endif

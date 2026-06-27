#include "EmptyStackException.h"

EmptyStackException::EmptyStackException()
    : std::runtime_error("The stack is empty")
{
}

#include "IllegalSubscriptException.h"

IllegalSubscriptException::IllegalSubscriptException(int index)
    : std::runtime_error("Subscript index must be 0 or 1"), index(index)
{
}

int IllegalSubscriptException::getIndex() const
{
    return index;
}

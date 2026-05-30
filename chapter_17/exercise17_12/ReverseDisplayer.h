#ifndef REVERSEDISPLAYER_H
#define REVERSEDISPLAYER_H

#include <string>

class ReverseDisplayer
{
public:
    void reverseDisplay(const std::string &s) const;
    void reverseDisplay(const std::string &s, int high) const;
};

#endif

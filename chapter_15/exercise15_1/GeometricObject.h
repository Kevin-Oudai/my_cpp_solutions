#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include <string>

class GeometricObject
{
public:
    GeometricObject();
    GeometricObject(const std::string &color, bool filled);

    std::string getColor() const;
    void setColor(const std::string &color);

    bool isFilled() const;
    void setFilled(bool filled);

private:
    std::string color;
    bool filled;
};

#endif

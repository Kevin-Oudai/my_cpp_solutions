# Exercise 15.3 UML

```text
MyPoint
-------------------------------
- x: double
- y: double
-------------------------------
+ MyPoint()
+ MyPoint(x, y)
+ getX() const: double
+ getY() const: double
+ distance(endPoint) const: double

ThreeDPoint extends MyPoint
-------------------------------
- z: double
-------------------------------
+ ThreeDPoint()
+ ThreeDPoint(x, y, z)
+ getZ() const: double
+ distance(endPoint) const: double
```

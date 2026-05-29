# Exercise 15.1 UML

```text
GeometricObject
-------------------------------
- color: string
- filled: bool
-------------------------------
+ GeometricObject()
+ GeometricObject(color, filled)
+ getColor() const: string
+ setColor(color): void
+ isFilled() const: bool
+ setFilled(filled): void

Triangle extends GeometricObject
-------------------------------
- side1: double
- side2: double
- side3: double
-------------------------------
+ Triangle()
+ Triangle(side1, side2, side3)
+ getSide1() const: double
+ getSide2() const: double
+ getSide3() const: double
+ getArea() const: double
+ getPerimeter() const: double
```

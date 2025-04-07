#pragma once
#include "Point.h"

class Square
{
private:
    Point point1;
    Point point2;
    Point point3;
    Point point4; 
    double sideLength;
    void validateSquare();
    double calculateDistance(const Point& p1, const Point& p2) const;
    Point calculateFourthPoint() const; 
public:
    Square(const Point& p1, const Point& p2, const Point& p3);
    double getArea() const;
    double getPerimeter() const;
    bool containsPoint(const Point& p) const;
};

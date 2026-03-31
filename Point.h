#pragma once
class Point
{
private:
    double x;
    double y;
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
};

bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);

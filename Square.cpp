#include <cmath>
#include <stdexcept>
#include "Square.h"

Square::Square(const Point& p1, const Point& p2, const Point& p3)
    : point1(p1), point2(p2), point3(p3)
{
    validateSquare();
}

void Square::validateSquare()
{
    // Проверка, что все точки разные
    if (point1 == point2 || point1 == point3 || point2 == point3)
    {
        throw std::invalid_argument("Точки квадрата должны быть разными");
    }

    // Вычисляем длины сторон
    double side1 = calculateDistance(point1, point2);
    double side2 = calculateDistance(point2, point3);

    // Проверяем, что стороны равны
    if (std::abs(side1 - side2) > std::numeric_limits<double>::epsilon())
    {
        throw std::invalid_argument("Точки не образуют квадрат (стороны не равны)");
    }

    sideLength = side1;
}

double Square::calculateDistance(const Point& p1, const Point& p2) const
{
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return std::sqrt(dx * dx + dy * dy);
}

double Square::getArea() const
{
    return sideLength * sideLength;
}

double Square::getPerimeter() const
{
    return 4 * sideLength;
}

#include <cmath>
#include <stdexcept>
#include <limits>
#include "Square.h"

Square::Square(const Point& p1, const Point& p2, const Point& p3)
    : point1(p1), point2(p2), point3(p3)
{
    point4 = calculateFourthPoint(); 
    validateSquare();
}

void Square::validateSquare()
{
    if (point1 == point2 || point1 == point3 || point1 == point4 ||
        point2 == point3 || point2 == point4 || point3 == point4)
    {
        throw std::invalid_argument("Точки квадрата должны быть разными");
    }

    // Вычисляем длины сторон и диагоналей
    double side1 = calculateDistance(point1, point2);
    double side2 = calculateDistance(point2, point3);
    double diagonal = calculateDistance(point1, point3);

    // Проверяем по теореме Пифагора (стороны равны и диагональ = сторона * √2)
    if (std::abs(side1 - side2) > std::numeric_limits<double>::epsilon() ||
        std::abs(diagonal - side1 * std::sqrt(2)) > std::numeric_limits<double>::epsilon())
    {
        throw std::invalid_argument("Точки не образуют квадрат");
    }

    sideLength = side1;
}

Point Square::calculateFourthPoint() const
{
    // Вычисляем вектор между точками 1 и 2
    double dx = point2.getX() - point1.getX();
    double dy = point2.getY() - point1.getY();

    // Поворачиваем вектор на 90 градусов и добавляем к точке 3
    return Point(point3.getX() - dy, point3.getY() + dx);
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

bool Square::containsPoint(const Point& p) const
{
    // Проверяем, что точка лежит внутри квадрата
    // Используем метод проекций на стороны
    double minX = std::min({ point1.getX(), point2.getX(), point3.getX(), point4.getX() });
    double maxX = std::max({ point1.getX(), point2.getX(), point3.getX(), point4.getX() });
    double minY = std::min({ point1.getY(), point2.getY(), point3.getY(), point4.getY() });
    double maxY = std::max({ point1.getY(), point2.getY(), point3.getY(), point4.getY() });

    return p.getX() >= minX && p.getX() <= maxX &&
        p.getY() >= minY && p.getY() <= maxY;
}

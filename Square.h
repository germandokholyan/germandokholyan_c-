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
    /**
     * @brief Проверяет, что точки образуют квадрат
     * @throws std::invalid_argument Если точки не образуют квадрат или совпадают
     */
    void validateSquare() const;
    /**
     * @brief Вычисляет расстояние между двумя точками
     * @param p1 Первая точка
     * @param p2 Вторая точка
     * @return Расстояние между точками
     */
    double calculateDistance(const Point& p1, const Point& p2) const;
    /**
     * @brief Вычисляет четвертую точку квадрата по трем заданным
     * @return Четвертая точка квадрата
     */
    Point calculateFourthPoint() const; 
public:
    Square(const Point& p1, const Point& p2, const Point& p3);
    double getArea() const;
    double getPerimeter() const;
    bool containsPoint(const Point& p) const;
};

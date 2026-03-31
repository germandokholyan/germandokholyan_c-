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
    /**
     * @brief Конструктор квадрата по трем точкам
     * @param p1 Первая точка квадрата
     * @param p2 Вторая точка квадрата
     * @param p3 Третья точка квадрата
     * @throws std::invalid_argument Если точки не образуют квадрат или совпадают
     */
    Square(const Point& p1, const Point& p2, const Point& p3);
    /**
     * @brief Вычисляет площадь квадрата
     * @return Площадь квадрата
     */
    double getArea() const;
    /**
     * @brief Вычисляет периметр квадрата
     * @return Периметр квадрата
     */
    double getPerimeter() const;
    /**
     * @brief Проверяет принадлежность точки квадрату
     * @param p Точка для проверки
     * @return true, если точка принадлежит квадрату, иначе false
     */
    bool containsPoint(const Point& p) const;
};

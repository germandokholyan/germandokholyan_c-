// Point.h
#include <iostream>
#include <stdexcept>

/**
 * Класс для представления точки на плоскости
 * с целочисленными координатами
 */
class Point {
private:
    unsigned int x; // Координата X
    unsigned int y; // Координата Y
    static unsigned int max_coord; // Максимальное значение координат

public:
    /**
     * Конструктор по умолчанию (0, 0)
     */
    Point() : x(0), y(0) {}

    /**
     * Основной конструктор точки
     * @param x координата X
     * @param y координата Y
     * @throws std::out_of_range если координаты превышают max_coord
     */
    Point(unsigned int x, unsigned int y);

    /**
     * Устанавливает максимальное значение для координат
     * @param max максимальное значение координат
     */
    static void setMaxCoord(unsigned int max);

    // Геттеры
    unsigned int getX() const { return x; }
    unsigned int getY() const { return y; }

    // Сеттеры
    void setX(unsigned int x);
    void setY(unsigned int y);

    /**
     * Оператор сравнения точек
     * @param other другая точка
     * @return true если точки равны
     */
    bool operator==(const Point& other) const;
    
    /**
     * @brief Оператор сравнения на неравенство
     * @param other Сравниваемая точка
     * @return true если координаты различаются, иначе false
     */
    bool operator!=(const Point& other) const;
    

    /** 
     * Оператор вывода точки в поток
     * Формат: (x,y)
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * Оператор ввода точки из потока
     * Формат: (x,y)
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};

#include "Shape.h"
#include "Point.h"
#include <cmath>

/**
 * Класс для представления овала (эллипса) на плоскости
 * Наследуется от абстрактного класса Shape
 */
class Oval : public Shape {
private:
    Point center;  // Центр овала
    unsigned int a; // Большая полуось
    unsigned int b; // Малая полуось

public:
    /**
     * Конструктор по умолчанию
     */
    Oval() : a(0), b(0) {}

    /**
     * Основной конструктор овала
     * @param center центр овала
     * @param a большая полуось
     * @param b малая полуось
     * @throws std::invalid_argument если полуоси равны нулю
     */
    Oval(const Point& center, unsigned int a, unsigned int b);

    // Реализация методов Shape
    std::string toString() const override;
    void readFromStream(std::istream& is) override;

    /**
     * Вычисляет площадь овала
     * @return площадь (π * a * b)
     */
    double getArea() const;

    /**
     * Вычисляет приближенный периметр овала
     * @return приближенное значение периметра
     */
    double getPerimeter() const;

    /**
     * Проверяет принадлежность точки овалу
     * @param point точка для проверки
     * @return true если точка внутри или на границе овала
     */
    bool contains(const Point& point) const;

    /**
     * Статический метод для преобразования овала в строку
     */
    static std::string toString(const Oval& oval);

    /**
     * Статический метод для создания овала из потока
     */
    static Oval fromStream(std::istream& is);
};

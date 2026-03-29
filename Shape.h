
#include <string>
#include <iostream>

/**
 * Абстрактный базовый класс для всех фигур на плоскости
 * Определяет общий интерфейс для работы с фигурами
 */
class Shape {
public:
    virtual ~Shape() {}

    /**
     * Преобразует фигуру в строку
     * @return строковое представление фигуры
     */
    virtual std::string toString() const = 0;

    /**
     * Читает параметры фигуры из потока
     * @param is входной поток
     */
    virtual void readFromStream(std::istream& is) = 0;

    /**
     * Оператор вывода фигуры в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        os << shape.toString();
        return os;
    }
};

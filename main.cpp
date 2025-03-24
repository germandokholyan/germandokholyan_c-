#include <iostream>
#include <string>
#include "Point.h"
#include "Square.h"

double getCoordinate(const std::string& message);

int main()
{
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Введите координаты трех точек квадрата:\n";
        
        double x = getCoordinate("Точка 1 - x: ");
        double y = getCoordinate("Точка 1 - y: ");
        Point point1(x, y);

        x = getCoordinate("Точка 2 - x: ");
        y = getCoordinate("Точка 2 - y: ");
        Point point2(x, y);

        x = getCoordinate("Точка 3 - x: ");
        y = getCoordinate("Точка 3 - y: ");
        Point point3(x, y);

        Square square(point1, point2, point3);

        std::cout << "Площадь квадрата: " << square.getArea() << std::endl;
        std::cout << "Периметр квадрата: " << square.getPerimeter() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

double getCoordinate(const std::string& message)
{
    std::cout << message;
    double coordinate;
    std::cin >> coordinate;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Некорректный ввод координаты");
    }
    return coordinate;
}

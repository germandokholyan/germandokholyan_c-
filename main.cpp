#include <iostream>
#include <string>
#include "Point.h"
#include "Square.h"

Point getPoint(const std::string& pointName);

int main()
{
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Введите координаты трех точек квадрата:\n";

        Point point1 = getPoint("1");
        Point point2 = getPoint("2");
        Point point3 = getPoint("3");

        Square square = Square(point1, point2, point3);

        std::cout << "Площадь квадрата: " << square.getArea() << std::endl;
        std::cout << "Периметр квадрата: " << square.getPerimeter() << std::endl;

        // Дополнительная проверка точки
        Point testPoint = getPoint("для проверки принадлежности квадрату");
        if (square.containsPoint(testPoint)) {
            std::cout << "Точка лежит внутри квадрата" << std::endl;
        }
        else {
            std::cout << "Точка не лежит внутри квадрата" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

Point getPoint(const std::string& pointName)
{
    std::cout << "Точка " << pointName << ":\n";
    std::cout << "x: ";
    double x = 0.0;
    std::cin >> x;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Некорректный ввод координаты x");
    }

    std::cout << "y: ";
    double y;
    std::cin >> y;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Некорректный ввод координаты y");
    }

    return Point(x, y);
}

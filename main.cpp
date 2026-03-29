#include <iostream>
#include "Oval.h"

int main() {
    try {
        // Установка максимальных координат
        Point::setMaxCoord(1920);
        
        // Создание овала
        Point center(100, 100);
        Oval oval(center, 50, 30);
        
        // Вывод информации
        std::cout << "Создан овал: " << oval << std::endl;
        std::cout << "Площадь: " << oval.getArea() << std::endl;
        std::cout << "Периметр: " << oval.getPerimeter() << std::endl;
        
        // Проверка точки
        Point testPoint(110, 105);
        if (oval.contains(testPoint)) {
            std::cout << "Точка " << testPoint << " внутри овала" << std::endl;
        }
        
        // Чтение овала из консоли
        std::cout << "Введите овал (формат: (x,y) a b): ";
        Oval oval2;
        std::cin >> oval2;
        std::cout << "Вы ввели: " << oval2 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

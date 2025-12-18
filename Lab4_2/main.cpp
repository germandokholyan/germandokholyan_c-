#include <iostream>
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstGenerator.h"
#include "ZeroGenerator.h"
enum class FillMethod {
    Random = 1,
    FromKeyboard,
    ConstantValue,
    Zero
};

int main()
{
    try {
        int n;
        int choice;

        std::cout << "Введите размер массива n: ";
        std::cin >> n;

        std::cout << "Выберите способ заполнения массива:\n";
        std::cout << "1. Случайными числами\n";
        std::cout << "2. Вводом с клавиатуры\n";
        std::cout << "3. Константным значением\n";
        std::cout << "4. Нулями\n";
        std::cin >> choice;

        // Создаем генератор в зависимости от выбора пользователя
        std::unique_ptr<miit::algebra::Generator<int>> gen = nullptr;

        switch (static_cast<FillMethod>(choice)) {
            case FillMethod::Random: {
                gen = std::make_unique<miit::algebra::RandomGenerator>(-100, 100);
                break;
            }
            case FillMethod::FromKeyboard: {
                gen = std::make_unique<miit::algebra::IStreamGenerator>(std::cin);
                break;
            }
            case FillMethod::ConstantValue: {
                int constValue;
                std::cout << "Введите константное значение: ";
                std::cin >> constValue;
                gen = std::make_unique<miit::algebra::ConstGenerator>(constValue);
                break;
            }
            case FillMethod::Zero: {
                gen = std::make_unique<miit::algebra::ZeroGenerator>();
                break;
            }
            default: {
                std::cerr << "Неверный выбор!" << std::endl;
                return 1;
            }
        }

        // --- Пункт 1 ---
        std::cout << "\n=== Пункт 1: Заменить первый отрицательный элемент нулем ===" << std::endl;
        {
            miit::algebra::Ex1 ex1(n, std::make_unique<miit::algebra::RandomGenerator>(-100, 100));
            ex1.fillMatrix();
            std::cout << "Исходный массив: " << ex1.getMatrixAsString() << std::endl;
            ex1.Task1();
            std::cout << "После выполнения задачи 1: " << ex1.getMatrixAsString() << std::endl;
        }

        // --- Пункт 2 ---
        std::cout << "\n=== Пункт 2: Вставить число K после всех элементов, кратных своему номеру ===" << std::endl;
        {
            miit::algebra::Ex2 ex2(n, std::make_unique<miit::algebra::RandomGenerator>(-100, 100));
            ex2.fillMatrix();
            std::cout << "Исходный массив: " << ex2.getMatrixAsString() << std::endl;
            int K;
            std::cout << "Введите значение K: ";
            std::cin >> K;
            ex2.Task2(K);
            // Вывод результата не предусмотрен в задании, поэтому просто выполняем задачу
        }

        // --- Пункт 3 ---
        std::cout << "\n=== Пункт 3: Сформировать массив A по правилу ===" << std::endl;
        {
            miit::algebra::Ex3 ex3(n, std::make_unique<miit::algebra::RandomGenerator>(-100, 100));
            ex3.fillMatrix();
            std::cout << "Исходный массив D: " << ex3.getMatrixAsString() << std::endl;
            ex3.Task2();
            std::cout << "Массив A после преобразования: " << ex3.getMatrixAsString() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

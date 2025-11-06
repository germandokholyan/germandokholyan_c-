#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Variant5Exercise.h"

using namespace miit::algebra;

int main()
{
    std::cout << "=== Вариант 5 ===" << std::endl;
    
    // Создание массива
    auto matrix = std::make_unique<Matrix<int>>(6);
    
    // Выбор генератора
    std::cout << "Выберите способ заполнения:" << std::endl;
    std::cout << "1 - Случайные числа [-100; 100]" << std::endl;
    std::cout << "2 - Ввод с клавиатуры" << std::endl;
    
    int choice;
    std::cin >> choice;
    
    std::unique_ptr<Generator> generator;
    
    if (choice == 1)
    {
        generator = std::make_unique<RandomGenerator>(-100, 100);
        std::cout << "Заполнение случайными числами..." << std::endl;
    }
    else
    {
        std::cout << "Введите " << matrix->get_size() << " элементов:" << std::endl;
        generator = std::make_unique<IStreamGenerator>();
    }
    
    // Заполнение массива
    matrix->fill(*generator);
    std::cout << "Исходный массив: " << *matrix << std::endl;
    
    // Создание задания
    Variant5Exercise exercise(std::move(matrix), std::move(generator));
    
    // Задание 1
    exercise.Task1();
    std::cout << "После задания 1: " << exercise.get_matrix() << std::endl;
    
    // Задание 2
    int K = 999;
    exercise.Task2(K);
    std::cout << "После задания 2 (K=" << K << "): " << exercise.get_matrix() << std::endl;
    
    // Задание 3
    auto result = exercise.Task3();
    std::cout << "Результат задания 3: " << result << std::endl;
    
    return 0;
}

#pragma once
#include "Exercise.h"
namespace miit::algebra {
    /**
     * @brief Класс, реализующий первый пункт задания (Заменить первый отрицательный элемент нулем).
     */
    class Ex1 : public Exercise {
    public:
        /**
         * @brief Конструктор.
         * @param n Размер массива.
         * @param gen Указатель на генератор значений.
         */
        Ex1(int n, std::unique_ptr<Generator<int>> gen);

        /**
         * @brief Выполняет задачу 1: заменяет первый отрицательный элемент нулем.
         */
        void Task1() override;
        /**
         * @brief Выполняет задачу 2: не используется в этом пункте.
         */
        void Task2() override;
    };
} 

#pragma once
#include "Exercise.h"
namespace miit::algebra {
    /**
     * @brief Класс, реализующий третий пункт задания (Из элементов массива D сформировать массив A той же размерности по правилу...).
     */
    class Ex3 : public Exercise {
    public:
        /**
         * @brief Конструктор.
         * @param n Размер массива.
         * @param gen Указатель на генератор значений.
         */
        Ex3(int n, std::unique_ptr<Generator<int>> gen);
        /**
         * @brief Выполняет задачу 1: не используется в этом пункте.
         */
        void Task1() override;
        /**
         * @brief Выполняет задачу 2: формирует массив A по правилу.
         */
        void Task2() override;
    };
}

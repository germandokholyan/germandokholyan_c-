#pragma once
#include "Generator.h"
#include <random>
namespace miit::algebra {
    /**
     * @brief Генератор случайных чисел.
     */
    class RandomGenerator : public Generator<int> {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief Конструктор.
         * @param min Минимальное значение.
         * @param max Максимальное значение.
         */
        RandomGenerator(const int min, const int max);
        /**
         * @brief Генерирует случайное число в заданном диапазоне.
         * @return Случайное целое число.
         */
        int generate() override;
    };
}

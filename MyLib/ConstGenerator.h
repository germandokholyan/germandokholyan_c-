#pragma once
#include "Generator.h"
namespace miit::algebra {
    /**
     * @brief Генератор, возвращающий константное значение.
     */
    class ConstGenerator : public Generator<int> {
    private:
        int value;
    public:
        /**
         * @brief Конструктор.
         * @param val Константное значение.
         */
        explicit ConstGenerator(int val);
        /**
         * @brief Возвращает константное значение.
         * @return Константное целое число.
         */
        int generate() override;
    };
} // namespace miit::algebra

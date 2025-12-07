#pragma once
#include "Generator.h"
#include <iostream>
namespace miit::algebra {
    /**
     * @brief Генератор, читающий значения из потока ввода.
     * @note Этот класс принимает ссылку на поток, но сам не содержит логики ввода-вывода.
     * Логика ввода-вывода остается в консольном приложении.
     */
    class IStreamGenerator : public Generator<int> {
    private:
        std::istream& in;
    public:
        /**
         * @brief Конструктор.
         * @param in Поток ввода (по умолчанию std::cin).
         */
        explicit IStreamGenerator(std::istream& in = std::cin);
        /**
         * @brief Читает значение из потока ввода.
         * @return Прочитанное целое число.
         */
        int generate() override;
    };
} // namespace miit::algebra

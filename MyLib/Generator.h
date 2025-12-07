#pragma once

namespace miit::algebra {

    /**
     * @brief Базовый абстрактный класс генератора значений.
     */
    class Generator {
    public:
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = 0;

        /**
         * @brief Генерирует следующее значение.
         * @return Сгенерированное целое число.
         */
        virtual int generate() = 0;
    };

    inline Generator::~Generator() = default;

} // namespace miit::algebra

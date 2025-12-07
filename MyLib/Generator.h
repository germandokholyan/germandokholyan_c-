#pragma once
namespace miit::algebra {
    /**
     * @brief Базовый абстрактный шаблонный класс генератора значений.
     * @tparam T Тип генерируемого значения.
     */
    template<typename T>
    class Generator {
    public:
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = default;
        /**
         * @brief Генерирует следующее значение.
         * @return Сгенерированное значение типа T.
         */
        virtual T generate() = 0;
    };
}

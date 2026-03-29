#pragma once
#include "Generator.h"
namespace miit::algebra {
    /**
     * @brief Генератор, возвращающий ноль.
     */
    class ZeroGenerator : public Generator<int> {
    public:
        /**
         * @brief Конструктор.
         */
        ZeroGenerator() = default;

        /**
         * @brief Возвращает ноль.
         * @return 0.
         */
        int generate() override;
    };
}

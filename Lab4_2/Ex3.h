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
         * @brief Выполняет задачу 2: формирует массив A по правилу.
         */
        void execute(); // Изменено: без параметров, так как правило не требует дополнительных данных
    };

}

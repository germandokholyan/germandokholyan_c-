#pragma once
#include "Exercise.h"
namespace miit::algebra {

    /**
     * @brief Класс, реализующий второй пункт задания (Вставить число K после всех элементов, кратных своему номеру).
     */
    class Ex2 : public Exercise {
    public:
        /**
         * @brief Конструктор.
         * @param n Размер массива.
         * @param gen Указатель на генератор значений.
         */
        Ex2(int n, std::unique_ptr<Generator<int>> gen);

        /**
         * @brief Выполняет задачу 2: вставляет K после всех элементов, кратных своему номеру.
         * @param K Значение для вставки.
         */
        void execute(int K); 
    };

}

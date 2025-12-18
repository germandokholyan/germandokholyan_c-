#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>
namespace miit::algebra {
    /**
     * @brief Абстрактный базовый класс для выполнения заданий.
     */
    class Exercise {
    protected:
        Matrix<int> matrix;
        std::unique_ptr<Generator<int>> generator;
    public:
        /**
         * @brief Конструктор.
         * @param n Размер массива.
         * @param gen Указатель на генератор значений.
         */
        Exercise(int n, std::unique_ptr<Generator<int>> gen);
        /**
         * @brief Деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Заполняет массив с помощью генератора.
         */
        void fillMatrix();

        /**
         * @brief Чисто виртуальный метод для задачи 1.
         */
        virtual void Task1() = 0;

        /**
         * @brief Чисто виртуальный метод для задачи 2.
         */
        virtual void Task2() = 0;

        /**
         * @brief Возвращает текущее состояние массива в виде строки.
         * @return Строка с содержимым массива.
         */
        std::string getMatrixAsString() const;
    };

}

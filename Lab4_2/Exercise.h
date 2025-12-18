#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>
#include <string>

namespace miit::algebra {

    /**
     * @brief Базовый класс для выполнения заданий.
     */
    class Exercise {
    protected:
        std::unique_ptr<Matrix<int>> matrix;
        std::unique_ptr<Generator<int>> generator;

    public:
        /**
         * @brief Конструктор.
         * @param n Размер массива.
         * @param gen Указатель на генератор значений.
         */
        Exercise(int n, std::unique_ptr<Generator<int>> gen);

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Заполняет массив с помощью генератора.
         */
        void fillMatrix();

        /**
         * @brief Выполняет основную логику задания.
         */
        virtual void execute() = 0; 

        /**
         * @brief Возвращает текущее состояние массива в виде строки.
         * @return Строка с содержимым массива.
         */
        std::string getMatrixAsString() const;
    };

} 

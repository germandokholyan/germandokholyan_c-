#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    protected:
        std::unique_ptr<Matrix<int>> matrix;
        std::unique_ptr<Generator> generator;

    public:
        Exercise(std::unique_ptr<Matrix<int>> matrix, std::unique_ptr<Generator> generator);
        virtual ~Exercise() = default;

        virtual void Task1() = 0;
        virtual void Task2(int K) = 0;

        const Matrix<int>& get_matrix() const;
    };
}

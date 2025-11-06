#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Variant5Exercise : public Exercise
    {
    public:
        Variant5Exercise(std::unique_ptr<Matrix<int>> matrix, std::unique_ptr<Generator> generator);

        void Task1() override;
        void Task2(int K) override;
        Matrix<int> Task3();

    private:
        bool is_multiple_of_index(int value, size_t index) const;
    };
}

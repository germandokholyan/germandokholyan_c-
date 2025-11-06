#include "Exercise.h"

miit::algebra::Exercise::Exercise(std::unique_ptr<Matrix<int>> matrix, std::unique_ptr<Generator> generator)
    : matrix(std::move(matrix)), generator(std::move(generator))
{
}

const miit::algebra::Matrix<int>& miit::algebra::Exercise::get_matrix() const
{
    return *matrix;
}

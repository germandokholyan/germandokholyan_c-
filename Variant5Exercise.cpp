#include "Variant5Exercise.h"

miit::algebra::Variant5Exercise::Variant5Exercise(
    std::unique_ptr<Matrix<int>> matrix, 
    std::unique_ptr<Generator> generator)
    : Exercise(std::move(matrix), std::move(generator))
{
}

void miit::algebra::Variant5Exercise::Task1()
{
    auto& mat = *matrix;
    for (size_t i = 0; i < mat.get_size(); ++i)
    {
        if (mat[i] < 0)
        {
            mat[i] = 0;
            break;
        }
    }
}

bool miit::algebra::Variant5Exercise::is_multiple_of_index(int value, size_t index) const
{
    size_t position = index + 1;
    return (position != 0) && (value % static_cast<int>(position) == 0);
}

void miit::algebra::Variant5Exercise::Task2(int K)
{
    auto& mat = *matrix;
    size_t original_size = mat.get_size();
    
    size_t insert_count = 0;
    for (size_t i = 0; i < original_size; ++i)
    {
        if (is_multiple_of_index(mat[i], i))
        {
            insert_count++;
        }
    }

    if (insert_count == 0) return;

    size_t new_size = original_size + insert_count;
    Matrix<int> new_matrix(new_size);
    
    size_t new_index = 0;
    for (size_t i = 0; i < original_size; ++i)
    {
        new_matrix[new_index++] = mat[i];
        if (is_multiple_of_index(mat[i], i))
        {
            new_matrix[new_index++] = K;
        }
    }

    *matrix = std::move(new_matrix);
}

miit::algebra::Matrix<int> miit::algebra::Variant5Exercise::Task3()
{
    const auto& D = *matrix;
    size_t size = D.get_size();
    Matrix<int> A(size);

    for (size_t i = 0; i < size; ++i)
    {
        size_t position = i + 1;
        if (position % 2 == 0)
        {
            A[i] = (position - 1) * D[i];
        }
        else
        {
            A[i] = D[i] * static_cast<int>(position) * 2;
        }
    }

    return A;
}

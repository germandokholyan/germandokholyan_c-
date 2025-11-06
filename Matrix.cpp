#include "Matrix.h"
#include "Generator.h"
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : data(std::make_unique<T[]>(size)), size(size) {}

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : Matrix(other.size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept 
        : data(std::move(other.data)), size(other.size)
    {
        other.size = 0;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            auto new_data = std::make_unique<T[]>(other.size);
            for (size_t i = 0; i < other.size; ++i)
            {
                new_data[i] = other.data[i];
            }
            data = std::move(new_data);
            size = other.size;
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    T& Matrix<T>::operator*()
    {
        if (size == 0)
        {
            throw std::out_of_range("Matrix is empty");
        }
        return data[0];
    }

    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
    {
        std::string result = "[";
        for (size_t i = 0; i < size; ++i)
        {
            result += std::to_string(data[i]);
            if (i < size - 1)
            {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    template<typename T>
    void Matrix<T>::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
    {
        os << matrix.to_string();
        return os;
    }

    // Явное инстанцирование
    template class Matrix<int>;
}

#pragma once
#include <iostream>
#include <memory>
#include <string>

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
    private:
        std::unique_ptr<T[]> data;
        size_t size;

    public:
        // Конструкторы по умолчанию
        Matrix();
        Matrix(size_t size);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        
        // Деструктор
        ~Matrix() = default;

        // Операторы
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        T& operator*();

        // Операторы сдвига
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);

        // Методы
        size_t get_size() const;
        std::string to_string() const;
        void fill(Generator& generator);
    };
}

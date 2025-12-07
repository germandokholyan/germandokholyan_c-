#pragma once
#include <string>
#include <stdexcept>

namespace miit::algebra {

    template<typename T>
    class Matrix {
    private:
        T* data;
        int size;

    public:
        // Конструктор по умолчанию
        Matrix() : data(nullptr), size(0) {}

        // Конструктор с размером
        explicit Matrix(int n) : data(new T[n]{}), size(n) {}

        // Конструктор копирования
        Matrix(const Matrix& other) : data(new T[other.size]), size(other.size) {
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        // Конструктор перемещения
        Matrix(Matrix&& other) noexcept : data(other.data), size(other.size) {
            other.data = nullptr;
            other.size = 0;
        }

        // Оператор присваивания (копирование)
        Matrix& operator=(const Matrix& other) {
            if (this != &other) {
                delete[] data;
                data = new T[other.size];
                size = other.size;
                for (int i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        // Оператор присваивания (перемещение)
        Matrix& operator=(Matrix&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = other.data;
                size = other.size;
                other.data = nullptr;
                other.size = 0;
            }
            return *this;
        }

        // Деструктор
        ~Matrix() {
            delete[] data;
        }

        // Оператор доступа по индексу
        T& operator[](int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Оператор доступа по индексу 
        const T& operator[](int index) const {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Получить размер массива
        int getSize() const {
            return size;
        }

        // Вывод содержимого в строку
        std::string toString() const {
            if (size == 0) return "[]";

            std::string result = "[";
            for (int i = 0; i < size; ++i) {
                result += std::to_string(data[i]);
                if (i < size - 1) {
                    result += ", ";
                }
            }
            result += "]";
            return result;
        }

        // Оператор сдвига влево (<<) для вывода в поток
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
            os << m.toString();
            return os;
        }
    };

} 

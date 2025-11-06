#pragma once
#include <iostream>
#include <memory>

template<typename T>
class Matrix {
private:
    std::unique_ptr<T[]> data;
    int size;
    
public:
    // Конструкторы
    Matrix() : data(nullptr), size(0) {}
    Matrix(int n) : data(std::make_unique<T[]>(n)), size(n) {}
    
    // Деструктор
    ~Matrix() = default;
    
    // Оператор []
    T& operator[](int index) {
        return data[index];
    }
    
    const T& operator[](int index) const {
        return data[index];
    }
    
    // Оператор *
    T& operator*() {
        return data[0];
    }
    
    // Операторы сдвига
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        os << "[";
        for (int i = 0; i < m.size; i++) {
            os << m.data[i];
            if (i < m.size - 1) os << ", ";
        }
        os << "]";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Matrix& m) {
        for (int i = 0; i < m.size; i++) {
            is >> m.data[i];
        }
        return is;
    }

    int get_size() const { return size; }
    
    void fill_with_zeros() {
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    
    void fill_with_value(T value) {
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }
};

#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

class Exercise {
protected:
    std::unique_ptr<Matrix<int>> arr;
    std::unique_ptr<Generator> gen;

public:
    Exercise(std::unique_ptr<Matrix<int>> array, std::unique_ptr<Generator> generator)
        : arr(std::move(array)), gen(std::move(generator)) {}
    
    virtual ~Exercise() = default;
    
    virtual void Task1() = 0;
    virtual void Task2(int K) = 0;
    virtual Matrix<int> Task3() = 0;
    
    const Matrix<int>& get_array() const {
        return *arr;
    }
    
    void fill_array() {
        for (int i = 0; i < arr->get_size(); i++) {
            (*arr)[i] = gen->generate();
        }
    }
};

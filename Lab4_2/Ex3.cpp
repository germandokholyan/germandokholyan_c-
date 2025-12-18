#include "Ex3.h"
namespace miit::algebra {
    Ex3::Ex3(int n, std::unique_ptr<Generator<int>> gen)
        : Exercise(n, std::move(gen)) {}
    void Ex3::Task2() {
        // Формируем массив A по правилу: если номер четный, то A_i = (i-1)*D_i, иначе A_i = D_i * i^2
        for (size_t i = 0; i < static_cast<size_t>(matrix->getSize()); ++i) {
            if ((i + 1) % 2 == 0) { // Четный номер (i+1 - потому что номера начинаются с 1)
                (*matrix)[i] = (static_cast<int>(i)) * (*matrix)[i]; // (i-1) в формуле -> i, так как i в цикле начинается с 0
            } else {
                (*matrix)[i] = (*matrix)[i] * (static_cast<int>(i) + 1) * (static_cast<int>(i) + 1); // i^2 -> (i+1)^2
            }
        }
    }

} 

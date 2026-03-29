#include "Ex2.h"
#include <vector>
#include <sstream>
miit::algebra::Ex2::Ex2(int n, std::unique_ptr<Generator<int>> gen)
    : Exercise(n, std::move(gen))
{
}
void miit::algebra::Ex2::Task2(int K)
{
    // Создаем временный вектор для нового массива
    std::vector<int> tempArray;
    for (int i = 0; i < matrix->getSize(); ++i) {
        tempArray.push_back((*matrix)[i]);
        // Проверяем, кратен ли элемент своему номеру (номер начинается с 1)
        if ((matrix)[i] != 0 && ((matrix)[i] % (i + 1)) == 0) {
            tempArray.push_back(K);
        }
    }
    // Создаем новый массив A
    Matrix<int> A(tempArray.size());
    for (int i = 0; i < tempArray.size(); ++i) {
        A[i] = tempArray[i];
    }
    // Формируем массив A по правилу: если номер четный, то A_i = (i-1)*D_i, иначе A_i = D_i * i^2
    for (int i = 0; i < A.getSize(); ++i) {
        if ((i + 1) % 2 == 0) { // Четный номер (i+1 - потому что номера начинаются с 1)
            A[i] = (i) * A[i]; // (i-1) в формуле -> i, так как i в цикле начинается с 0
        } else {
            A[i] = A[i] * (i + 1) * (i + 1); // i^2 -> (i+1)^2
        }
    }
}

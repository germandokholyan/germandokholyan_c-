#include "Ex1.h"
miit::algebra::Ex1::Ex1(int n, std::unique_ptr<Generator<int>> gen)
    : Exercise(n, std::move(gen))
{
}
void miit::algebra::Ex1::Task1()
{
    for (int i = 0; i < matrix->getSize(); ++i) {
        if ((*matrix)[i] < 0) {
            (*matrix)[i] = 0;
            break; // Заменяем только первый отрицательный элемент
        }
    }
}

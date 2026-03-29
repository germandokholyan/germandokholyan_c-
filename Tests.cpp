#include <iostream>
#include <memory>
#include <cassert>
#include "Matrix.h"
#include "Variant5Exercise.h"

class TestGenerator : public miit::algebra::Generator
{
private:
    int value;
public:
    TestGenerator(int val) : value(val) {}
    int generate() override { return value; }
};

void test_task1()
{
    std::cout << "Тест задания 1..." << std::endl;
    
    auto matrix = std::make_unique<miit::algebra::Matrix<int>>(4);
    auto generator = std::make_unique<TestGenerator>(1);
    
    (*matrix)[0] = 5;
    (*matrix)[1] = -3;
    (*matrix)[2] = 7;
    (*matrix)[3] = 2;
    
    miit::algebra::Variant5Exercise exercise(std::move(matrix), std::move(generator));
    exercise.Task1();
    
    assert(exercise.get_matrix()[1] == 0);
    std::cout << "Тест задания 1 пройден!" << std::endl;
}

void test_task2()
{
    std::cout << "Тест задания 2..." << std::endl;
    
    auto matrix = std::make_unique<miit::algebra::Matrix<int>>(3);
    auto generator = std::make_unique<TestGenerator>(1);
    
    (*matrix)[0] = 2;  // кратен 1
    (*matrix)[1] = 4;  // кратен 2
    (*matrix)[2] = 5;  // не кратен 3
    
    miit::algebra::Variant5Exercise exercise(std::move(matrix), std::move(generator));
    exercise.Task2(99);
    
    assert(exercise.get_matrix().get_size() == 5);
    assert(exercise.get_matrix()[1] == 99);
    assert(exercise.get_matrix()[3] == 99);
    std::cout << "Тест задания 2 пройден!" << std::endl;
}

int main()
{
    test_task1();
    test_task2();
    std::cout << "Все тесты пройдены!" << std::endl;
    return 0;
}

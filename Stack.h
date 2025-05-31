#pragma once
#include <initializer_list>
#include <string>
#include <ostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* topNode;
    size_t stackSize;

public:
    Stack();
    Stack(std::initializer_list<int> initList);
    ~Stack();

    // Конструкторы копирования и перемещения
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;

    // Операторы присваивания
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    // Основные операции стека
    void push(int value);
    int pop();
    int peek() const;
    
    // Вспомогательные методы
    bool isEmpty() const;
    size_t size() const;
    std::string toString() const;

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
};

#include "Stack.h"
#include <stdexcept>
#include <sstream>

// Конструктор по умолчанию
Stack::Stack() : topNode(nullptr), stackSize(0) {}

// Конструктор с инициализацией
Stack::Stack(std::initializer_list<int> initList) : Stack() {
    for (auto it = initList.end(); it != initList.begin(); ) {
        push(*(--it));
    }
}

// Деструктор
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Конструктор копирования
Stack::Stack(const Stack& other) : topNode(nullptr), stackSize(0) {
    Stack temp;
    Node* current = other.topNode;

    while (current != nullptr) {
        temp.push(current->data);
        current = current->next;
    }

    while (!temp.isEmpty()) {
        push(temp.pop());
    }
}

// Конструктор перемещения
Stack::Stack(Stack&& other) noexcept {
    topNode = nullptr;
    stackSize = 0;
    std::swap(topNode, other.topNode);
    std::swap(stackSize, other.stackSize);
}

// Оператор присваивания копированием
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        while (!isEmpty()) {
            pop();
        }

        Stack temp;
        Node* current = other.topNode;
        while (current != nullptr) {
            temp.push(current->data);
            current = current->next;
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
    return *this;
}

// Оператор присваивания перемещением
Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        while (!isEmpty()) {
            pop();
        }
        topNode = other.topNode;
        stackSize = other.stackSize;
        other.topNode = nullptr;
        other.stackSize = 0;
    }
    return *this;
}

// Добавление элемента в стек
void Stack::push(int value) {
    Node* newNode = new Node{ value, topNode };
    topNode = newNode;
    stackSize++;
}

// Удаление и возврат верхнего элемента
int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }

    Node* temp = topNode;
    int value = temp->data;
    topNode = topNode->next;
    delete temp;
    stackSize--;

    return value;
}

// Просмотр верхнего элемента без удаления
int Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

// Проверка на пустоту
bool Stack::isEmpty() const {
    return topNode == nullptr;
}

// Получение размера стека
size_t Stack::size() const {
    return stackSize;
}

// Преобразование стека в строку
std::string Stack::toString() const {
    std::ostringstream oss;
    Node* current = topNode;

    oss << "[";
    while (current != nullptr) {
        oss << current->data;
        if (current->next != nullptr) {
            oss << ", ";
        }
        current = current->next;
    }
    oss << "]";

    return oss.str();
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    os << stack.toString();
    return os;
}

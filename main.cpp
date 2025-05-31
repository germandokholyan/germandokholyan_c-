#include <iostream>
#include "../Stack/Stack.h"

void demonstrateStackOperations() {
    Stack stack;

    std::cout << "Создаем пустой стек\n";
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << "\n";

    std::cout << "\nДобавляем элементы (push): 10, 20, 30\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Содержимое стека: " << stack << "\n";
    std::cout << "Размер стека: " << stack.size() << "\n";
    std::cout << "Верхний элемент (peek): " << stack.peek() << "\n";

    std::cout << "\nУдаляем элемент (pop)\n";
    std::cout << "Удаленный элемент: " << stack.pop() << "\n";
    std::cout << "Содержимое стека: " << stack << "\n";

    std::cout << "\nСоздаем стек с инициализацией {1, 2, 3, 4, 5}\n";
    Stack initStack = { 1, 2, 3, 4, 5 };
    std::cout << "Содержимое стека: " << initStack << "\n";

    std::cout << "\nКопируем стек\n";
    Stack copiedStack = initStack;
    std::cout << "Скопированный стек: " << copiedStack << "\n";

    std::cout << "\nПрисваиваем стеки\n";
    stack = copiedStack;
    std::cout << "Присвоенный стек: " << stack << "\n";
}

int main() {
    try {
        demonstrateStackOperations();
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

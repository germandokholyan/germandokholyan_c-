#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
int main() {
    std::vector<int> input;
    int num;
    std::cout << "Введите числа (количество кратно 3): ";
    while (std::cin >> num) {
        input.push_back(num);
        if (std::cin.peek() == '\n') break;
    }
    if (input.size() % 3 != 0) {
        std::cerr << "Ошибка: количество элементов (" << input.size() 
                  << ") не делится на 3!" << std::endl;
        return 1;
    }
    // Создание списка L
    std::list<int> L(input.begin(), input.end());
    
    int Lsize = L.size();
    int third = Lsize / 3;
    std::ostream_iterator<int> pout_iterator(std::cout, " ");
    std::cout << "Результат: ";
    // Первая треть: в прямом порядке
    auto ptin_iterator = L.begin();
    auto end_first = ptin_iterator;
    std::advance(end_first, third);
    std::copy(ptin_iterator, end_first, pout_iterator);
    // Вторая треть: в обратном порядке
    auto start_second = end_first;
    auto end_second = start_second;
    std::advance(end_second, third);
    std::copy(std::make_reverse_iterator(end_second), 
              std::make_reverse_iterator(start_second), 
              pout_iterator);
    // Третья треть: в обратном порядке
    auto start_third = end_second;
    auto end_third = start_third;
    std::advance(end_third, third);
    std::copy(std::make_reverse_iterator(end_third), 
              std::make_reverse_iterator(start_third), 
              pout_iterator);
    std::cout << std::endl;
    return 0;
}

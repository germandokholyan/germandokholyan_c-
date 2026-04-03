#include "pt4.h"
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    // Инициализация задачи в PT4
    Task("PTask2");

    list<int> L;
    
    // Заполнение списка с использованием ptin_iterator
    // Читаем все входные числа в список L
    copy(ptin_iterator<int>(), ptin_iterator<int>(), back_inserter(L));

    // Проверка условия (количество делится на 3)
    if (L.empty() || L.size() % 3 != 0) {
        return 0;
    }

    auto third = L.size() / 3;

    // 1. Первая треть элементов в исходном порядке
    auto it_end_first = L.begin();
    advance(it_end_first, third);
    copy(L.begin(), it_end_first, ptout_iterator<int>());

    // 2. Вторая треть элементов в обратном порядке
    auto it_end_second = L.begin();
    advance(it_end_second, 2 * third);
    
    auto it_first_second = L.begin();
    advance(it_first_second, third);

    // Используем reverse_iterator для вывода второй трети задом наперед
    // Начинаем с it_end_second (элемент перед ним будет первым в выводе) 
    // и идем до it_first_second.
    copy(make_reverse_iterator(it_end_second), 
         make_reverse_iterator(it_first_second), 
         ptout_iterator<int>());

    // 3. Последняя треть элементов в обратном порядке
    // Начинаем с конца списка (L.end()) и идем до начала последней трети (it_end_second)
    copy(make_reverse_iterator(L.end()), 
         make_reverse_iterator(it_end_second), 
         ptout_iterator<int>());

    return 0;
}

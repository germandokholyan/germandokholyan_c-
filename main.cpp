#include "pt4.h"
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
void Solve() {
    Task("PTask2");
    // Заполнение списка с использованием ptin_iterator
    list<int> L;
    copy(ptin_iterator<int>(), ptin_iterator<int>(), back_inserter(L));
    if (L.empty() || L.size() % 3 != 0) 
    {
        // Обработка ошибки или пропуск
        return;
    }
    auto third = L.size() / 3;
    // Первая треть в исходном порядке
    auto it_end_first = L.begin();
    advance(it_end_first, third);
    copy(L.begin(), it_end_first, ptout_iterator<int>());
    // Вторая треть в обратном порядке
    auto it_end_second = L.begin();
    advance(it_end_second, 2 * third);
    auto it_first_second = L.begin();
    advance(it_first_second, third);
    copy(make_reverse_iterator(it_end_second), make_reverse_iterator(it_first_second), 
         ptout_iterator<int>());
    // Последняя треть в обратном порядке
    copy(make_reverse_iterator(L.end()), make_reverse_iterator(it_end_second), 
         ptout_iterator<int>());
}

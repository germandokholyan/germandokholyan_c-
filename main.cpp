#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("name");
    cout << "Numbers with even index (2nd, 4th, etc.): ";
    // Счетчик для отслеживания позиции элемента
    auto predicate = [index=0](double) mutable 
    {
        return (index++) % 2 == 0;  // пропускаем элементы с индексами 0,2,4...
    };                               // копируем элементы с индексами 1,3,5... (2-й, 4-й, 6-й)
    
    remove_copy_if(istream_iterator<double>(fin), istream_iterator<double>(),
                   ostream_iterator<double>(cout, " "), predicate);
    
    cout << endl;
    fin.close();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <functional>
int main() {
    std::string name;
    std::cout << "Введите имя файла: ";
    std::cin >> name;
    std::cout << "Введите элементы вектора (четное количество): ";
    std::vector<int> V(std::istream_iterator<int>(std::cin), 
                       std::istream_iterator<int>());
    if (V.size() % 2 != 0) {
        std::cerr << "Ошибка: количество элементов вектора должно быть четным!" << std::endl;
        return 1;
    }
    auto mid_iter = V.begin() + (V.size() / 2);
    std::set<int, std::greater<int>> first_half(V.begin(), mid_iter);
    std::set<int, std::greater<int>> second_half(mid_iter, V.end());
    std::ofstream outfile(name);
    if (!outfile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return 1;
    }
    std::ostream_iterator<int> file_out(outfile, "\n");
    std::set_difference(
        second_half.begin(), second_half.end(),
        first_half.begin(), first_half.end(),
        file_out
    );
    std::cout << "Результат успешно записан в файл '" << name << "'." << std::endl;
    outfile.close();
    return 0;
}

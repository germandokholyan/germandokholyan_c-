#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iterator>
#include <sstream>
struct less_abs {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};
int main() {
    int K;
    std::cout << "Введите K (> 0): ";
    std::cin >> K;
    std::cin.ignore(10000, '\n');
    std::cout << "Введите элементы вектора: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> V;
    V.assign(std::istream_iterator<int>(iss), 
             std::istream_iterator<int>());
    auto predicate = [K](int x) {
        return K >= std::abs(x);
    };
    int count = std::count_if(V.begin(), V.end(), predicate);
    std::cout << "Количество элементов, удовлетворяющих условию K >= |x|: " << count << std::endl;
    return 0;
}

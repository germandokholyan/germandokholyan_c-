#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
struct less_abs {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};
int main() {
    int K;
    std::cout << "Введите K (> 0): ";
    std::cin >> K;
    std::vector<int> V;
    int val;
    std::cout << "Введите элементы вектора: ";
    while (std::cin >> val) {
        V.push_back(val);
    }
    auto predicate = std::bind(std::not2(less_abs{}), K, std::placeholders::_1);
    int count = std::count_if(V.begin(), V.end(), predicate);
    std::cout << "Количество элементов, удовлетворяющих условию K >= |x|: " << count << std::endl;
    return 0;
}

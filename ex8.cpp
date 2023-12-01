#include <iostream>
#include <vector>
#include <functional>

template<typename T, typename Function>
std::vector<T> applyFunc(const std::vector<T>& input, Function func) {
    std::vector<T> result;
    for (const auto& element : input) {
        result.push_back(func(element));
    }
    return result;
}

int main() {
    // Пример использования функции
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto square = [](int x) { return x * x; };

    std::vector<int> squaredNumbers = applyFunc(numbers, square);

    for (const auto& number : squaredNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

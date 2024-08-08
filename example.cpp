#include <iostream>
#include <vector>

// Общий шаблон функции для sum
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

// Специализированная функция для int
int sum(int a, int b)
{
    return a + b;
}

// Специализированный шаблон функции для std::vector
template <>
std::vector<int> sum<std::vector<int>>(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> tmp(a.begin(), a.end());
    tmp.insert(tmp.end(), b.begin(), b.end());
    return tmp;
}
 
template <typename U>
std::vector<U> sum(std::vector<U> a, std::vector<U> b)
{
    std::vector<U> tmp(a.begin(), a.end());
    tmp.insert(tmp.end(), b.begin(), b.end());
    return tmp;
}



int main()
{
    std::cout << sum(7, 8) << std::endl; // Неявная инстанциация
    // std::cout << sum<int>(7.5, 9) << std::endl; // Явная инстанциация с несовпадающими типами

    // Пример использования специализации для вектора
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> result = sum(vec1, vec2);

    std::cout << "Результат вектора: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Раскомментирование приведет к ошибке компиляции, так как 7.5 - это double
}

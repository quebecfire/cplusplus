### Example

```c++
#include <iostream>
#include <tuple>

template<typename T>
T Add(T x, T y) {
    return x+y;
}

template<typename T>
T ArraySum(T* p_Array, int size) {
    T sum{};
    for (int i = 0; i < size; ++i) {
        sum += p_Array[i];
    }

    return sum;
}

template<typename T>
T Max(T* p_Array, int size) {
    T max{};
    for (int i = 0; i < size; ++i) {
        max = p_Array[i];
    }
    return max;
}

template<typename T>
std::pair<T, T> MinMax(T* p_Array, int size) {
    T max{};
    T min{};
    for (int i = 0; i < size; ++i) {
        if (max < p_Array[i]) {
            max = p_Array[i];
            continue;
        }
        if (min > p_Array[i]) {
            min = p_Array[i];
        }
    }
    return {max,min};
}

int main() {
    std::cout << Add(5, 3) << std::endl;
    std::cout << Add<double>(5, 3.2) << std::endl;
    int a[5] = {1, 2, 3, 4, 5};
    std::cout << ArraySum(a, 5) << std::endl;
    std::cout << Max(a, 5) << std::endl;
    std::cout << MinMax(a, 5).first << " | " << MinMax(a, 5).second << std::endl;
    return 0;
}
```
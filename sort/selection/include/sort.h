#ifndef SORT_H
#define SORT_H

#include <array>
#include <iostream>

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, std::array<T, N>& arr) {
    os << "[";
    for (const auto elem : arr) {
        os << " " << elem << " ";
    }
    os << "]" << std::endl;

    return os;
}

template<typename T, std::size_t N>
void swap(std::array<T, N>& arr, const std::size_t a, const std::size_t b) {
    auto helper = arr.at(b);
    arr.at(b) = arr.at(a);
    arr.at(a) = helper;
}

template<typename T, std::size_t N>
void selection_sort(std::array<T, N>& arr) {
    for (std::size_t j = 0; j < N; j++) {
        auto min_val = arr[j];
        auto min_idx = j;

        for (auto i = j + 1; i < N; i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
                min_idx = i;
            }
        }

        if (min_idx != j) {
            swap(arr, j, min_idx);
        }
    }

}


#endif

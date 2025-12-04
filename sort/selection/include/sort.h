#ifndef SORT_H
#define SORT_H

#include <array>

template<typename T, std::size_t N>
void swap(std::array<T, N>& arr, const std::size_t a, const std::size_t b) {
    auto helper = arr.at(b);
    arr.at(b) = arr.at(a);
    arr.at(a) = helper;
}

#endif

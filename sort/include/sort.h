#ifndef SORT_H
#define SORT_H

#include <array>
#include <cstddef>
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

template<typename T, std::size_t N_one, std::size_t N_two>
std::array<T, N_one + N_two> merge(std::array<T, N_one>& one, std::array<T, N_two>& two) {
    std::array<T, N_one + N_two> res{};

    // TODO: 0 or 1?
    std::size_t count_one = 0;
    std::size_t count_two = 0;
    std::size_t idx = 0;


    while (count_one < N_one && count_two < N_two) {
        if (one[count_one] < two[count_two]) {
            res[idx] = one[count_one];
            count_one++;
        } else {
            res[idx] = two[count_two];
            count_two++;
        }

        idx++;
    }

    // Array two has elements remaining
    if (count_one == N_one) {
            std::copy(two.begin() + count_two, two.end(), res.begin() + idx);
    }
    if (count_two == N_two) {
            std::copy(one.begin() + count_one, one.end(), res.begin() + idx);
    }

    return res;
}

template<typename T, std::size_t N>
std::array<T, N> merge_sort(const std::array<T, N>& arr) {
    if (N <= 1) {
        return arr;
    }

    std::array<T, N/2> lower;
    std::array<T, N - N/2> upper;

    std::copy(arr.begin(), arr.begin() + N/2, lower.begin());
    std::copy(arr.begin() + N/2, arr.end(), upper.begin());

    // Recursion stacks until first hit of N == 1
    // Once N == 1 the merge() function will break
    // each recursion step
    lower = merge_sort(lower);
    upper = merge_sort(upper);

    // This is only called when moving inside-out
    // after N == 1 returned values, lower and upper are set
    // and are merged here. That merge is returned again yielded
    // lower and upper values for the outer iteration call
    return merge(lower, upper);
}




#endif

#include <iostream>
#include "sort.h"

int main() {
    std::array<int, 5> arr = {-1, 12, 3, 17, 4};
    arr = merge_sort(arr);

    std::cout << arr << std::endl;
}

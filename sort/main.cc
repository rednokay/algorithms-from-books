#include <iostream>
#include "sort.h"

int main() {
    std::array<int, 7> arr = {5, -1, 12, 15, 1, -12, 7};
    swap(arr, 1, 2);

    std::cout << arr[2] << std::endl;
}

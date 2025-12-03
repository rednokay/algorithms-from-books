#include <iostream>
#include <array>
#include <optional>

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
    os << '[';
    if (!arr.empty()) {
        for (const auto& elem : arr) {
            os << ' ' << elem << ' ';
        }
    }
    os << ']';

    return os;
}

// Assume arr is and array of sorted integers of length N
template<std::size_t N>
std::optional<int> binary_search(const std::array<int, N>& arr, int key) {
    if (arr.empty())
        return std::nullopt;

    auto lower = 0;
    auto upper = arr.size();    // exceeding last index by 1

    if (key > arr.at(upper - 1))
        return std::nullopt;
    if (key < arr.at(lower))
        return std::nullopt;

    while (lower < upper) {
        const auto rel_mid = int((upper - lower)/2);
        const auto mid = lower + rel_mid;

        std::cout << '(' << lower << ", " << mid << ", "<< upper << "); " << arr.at(mid) << "\n";

        if (key == arr.at(mid)) {
            return mid;
        }

        if (key < arr.at(mid)) {
            upper = mid;
        } else if (key > arr.at(mid)){
            lower = mid + 1;
        }
    }

    return std::nullopt;
}

int main() {
    // constexpr std::array<int, 7> list = {-1, 2, 3, 7, 8, 9, 15};
    std::array<int, 5> list = {1, 3, 5, 7, 9};
    std::cout << "List in which to find in: " << list << "\n";

    int key;
    std::cout << "Which number do you want to find? ";
    std::cin >> key;

    const int index = binary_search(list, key).value_or(-1);
    std::cout << "The number " << key << " is located at index " << index << "\n";
}

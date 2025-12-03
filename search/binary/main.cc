#include <cstddef>
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
    auto upper = arr.size() - 1;

    if (key > arr.at(upper))
        return std::nullopt;
    if (key < arr.at(lower))
        return std::nullopt;

    std::optional<int> index = std::nullopt;

    while (lower != upper) {
        const int rel_mid = int((upper - lower)/2);
        const int mid = lower + rel_mid;

        std::cout << '(' << lower << ", " << mid << ", "<< upper << "); " << arr.at(mid) << "\n";

        if (key == arr.at(mid)) {
            index = mid;
            break;
        }

        if (rel_mid == 0) {
            index = (upper == mid + 1 && key == arr.at(upper)) ? upper : index;
            break;
        }

        if (key < arr.at(mid))
            upper = mid;
        if (key > arr.at(mid))
            lower = mid;
    }

    return index;
}

int main() {
    constexpr std::array<int, 7> list = {-1, 2, 3, 7, 8, 9, 15};
    std::cout << "List in which to find in: " << list << "\n";

    int key;
    std::cout << "Which number do you want to find? ";
    std::cin >> key;

    const int index = binary_search(list, key).value_or(-1);
    std::cout << "The number " << key << " is located at index " << index << "\n";
}

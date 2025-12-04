#include "catch2/catch_test_macros.hpp"
#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "sort.h"

TEST_CASE("The swap() function swaps the values of two std::array entries while not altering other values") {

    SECTION("Swapping two elements") {
        std::array<int, 7> arr = {5, -1, 12, 15, 1, -12, 7};

        swap(arr, 1, 5);

        REQUIRE(arr.at(5) == -1);
        REQUIRE(arr.at(1) == -12);
    }

    SECTION("Unswapped elements should remain untouched") {
        std::array<int, 5> arr = {5, -1, 12, 15, 7};

        swap(arr, 1, 3);
        std::array<int, 5> res = {5, 15, 12, -1, 7};

        REQUIRE(arr == res);
    }
}

TEST_CASE("The selection_sort() function sorts an std::array in increasing order") {

    SECTION("An unsorted array should be sorted") {
        std::array<int, 4> arr = {5, -1, 12, 7};
        std::array<int, 4> res = {-1, 5, 7, 12};

        selection_sort(arr);

        REQUIRE(arr == res);
    }

    SECTION("A sorted array sould remain sorted") {
        std::array<int, 4> arr = {-1, 5, 7, 12};
        std::array<int, 4> res = {-1, 5, 7, 12};

        selection_sort(arr);

        REQUIRE(arr == res);
    }
}

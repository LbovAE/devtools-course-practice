// Copyright 2022 Lbov Alexander

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/binary_search.h"

TEST(Lbov_Alexander_Binary_Search_Test, can_find_int) {
    std::vector<int> array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    BinarySearch<int> b;
    size_t result = b.BinSearch(0, array);
    ASSERT_EQ(3, result);
}

TEST(Lbov_Alexander_Binary_Search_Test, can_find_double) {
    std::vector<double> array = {
        -5.0, -3.0, -1.0, 0.0, 1.0, 3.0, 5.0
    };
    BinarySearch<double> b;
    size_t result = b.BinSearch(1.0, array);
    ASSERT_EQ(4, result);
}

TEST(Lbov_Alexander_Binary_Search_Test, can_find_string) {
    std::vector<std::string> array = {
        "a", "b", "c", "d", "e", "f"
    };
    BinarySearch<std::string> b;
    size_t result = b.BinSearch("b", array);
    ASSERT_EQ(1, result);
}

TEST(Lbov_Alexander_Binary_Search_Test, correct_work_on_missing_value) {
    std::vector<int> array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    BinarySearch<int> b;
    size_t result = b.BinSearch(1337, array);
    ASSERT_EQ(-1, result);
}

TEST(Lbov_Alexander_Binary_Search_Test, search_in_unsorted) {
    std::vector<int> array = {
        2, 1, 4, 3, 6, 5, 0
    };
    BinarySearch<int> b;
    size_t result = b.BinSearch(4, array);
    ASSERT_EQ(-1, result);
}

// Copyright 2022 Lbov Alexander

#ifndef MODULES_LBOV_ALEXANDER_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_LBOV_ALEXANDER_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <vector>
#include <string>

template <class T>
class BinarySearch {
 public:
    BinarySearch() {}
    ~BinarySearch() {}
    size_t BinSearch(T key, const std::vector<T>& array) {
        size_t left = 0, right = array.size() - 1;
        size_t middle = (left + right) / 2;
        bool flag = false;
        while (left <= right && !flag) {
            if (array[middle] == key) {
                flag = true;
            } else if (array[middle] > key) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            middle = (left + right) / 2;
        }
        if (flag) {
            return middle;
        } else {
            return -1;
        }
    }
};

#endif  // MODULES_LBOV_ALEXANDER_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

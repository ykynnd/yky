#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iterator>
#include "HeapSort.h"
template <typename T>
bool check(const std::vector<T>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i - 1] > v[i]) {
            return false;
        }
    }
    return true;
}

void testHeapSort() {
    const int size = 1000000;

    // 随机序列
    std::vector<int> randomVec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int& value : randomVec) {
        value = dis(gen);
    }

    // 有序序列
    std::vector<int> orderedVec(size, 1);

    // 逆序序列
    std::vector<int> reverseVec(size, 1);
    std::iota(reverseVec.rbegin(), reverseVec.rend(), 1);

    // 部分元素重复序列
    std::vector<int> partialRepeatVec(size);
    std::fill(partialRepeatVec.begin(), partialRepeatVec.begin() + size / 2, 1);
    std::iota(partialRepeatVec.begin() + size / 2, partialRepeatVec.end(), 2);

    // 测试 heapSort
    std::vector<int> testVec = randomVec;
    heapSort(testVec);
    std::cout << (check(testVec) ? "heapSort randomVec: PASS" : "heapSort randomVec: FAIL") << std::endl;

    testVec = orderedVec;
    heapSort(testVec);
    std::cout << (check(testVec) ? "heapSort orderedVec: PASS" : "heapSort orderedVec: FAIL") << std::endl;

    testVec = reverseVec;
    heapSort(testVec);
    std::cout << (check(testVec) ? "heapSort reverseVec: PASS" : "heapSort reverseVec: FAIL") << std::endl;

    testVec = partialRepeatVec;
    heapSort(testVec);
    std::cout << (check(testVec) ? "heapSort partialRepeatVec: PASS" : "heapSort partialRepeatVec: FAIL") << std::endl;

    // 测试 std::sort_heap
    testVec = randomVec;
    auto start1 = std::chrono::high_resolution_clock::now();
    std::sort_heap(testVec.begin(), testVec.end());
    auto end1 = std::chrono::high_resolution_clock::now();
    printTime("std::sort_heap", start1, end1);
    std::cout << (check(testVec) ? "std::sort_heap randomVec: PASS" : "std::sort_heap randomVec: FAIL") << std::endl;
    
    testVec = orderedVec;
    auto start2 = std::chrono::high_resolution_clock::now();
    std::sort_heap(testVec.begin(), testVec.end());
    auto end2 = std::chrono::high_resolution_clock::now();
    printTime("std::sort_heap", start2, end2);
    std::cout << (check(testVec) ? "std::sort_heap orderedVec: PASS" : "std::sort_heap orderedVec: FAIL") << std::endl;
    
    testVec = reverseVec;
    auto start3 = std::chrono::high_resolution_clock::now();
    std::sort_heap(testVec.begin(), testVec.end());
    auto end3 = std::chrono::high_resolution_clock::now();
    printTime("std::sort_heap", start3, end3);
    std::cout << (check(testVec) ? "std::sort_heap reverseVec: PASS" : "std::sort_heap reverseVec: FAIL") << std::endl;
    
    testVec = partialRepeatVec;
    auto start4 = std::chrono::high_resolution_clock::now();
    std::sort_heap(testVec.begin(), testVec.end());
    auto end4 = std::chrono::high_resolution_clock::now();
    printTime("std::sort_heap", start4, end4);
    std::cout << (check(testVec) ? "std::sort_heap partialRepeatVec: PASS" : "std::sort_heap partialRepeatVec: FAIL") << std::endl;
}


int main() {
    testHeapSort();
    return 0;
}
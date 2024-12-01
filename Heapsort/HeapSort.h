#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T>
void heapify(std::vector<T>& v, int n, int idx) {
    int largest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
    // 如果左节点存在且大于最大元素，则更新最大元素
    if (left < n && v[left]> v[largest]) {
        largest = left;
    }
    // 如果右节点存在且大于最大元素，则更新最大元素
    if (right < n && v[right]> v[largest]) {
        largest = right;
    }
    // 如果最大元素不是根，交换，并继续向下递归
    if (largest != idx) {
        swap(v[idx], v[largest]);
        heapify(v, n, largest); 
    }
}

template <typename T>
void makeheap(std::vector<T>& v) {
    int n = v.size();
    // 从最后一个非叶子节点开始，向下调整每个节点
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
}

//复制一个输出时间的函数。。。。

void printTime(const std::string& testName, std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> end) {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << testName << " took " << duration << " microseconds.\n";
}

template <typename T>
void heapSort(std::vector<T>& v){
	 auto start = std::chrono::high_resolution_clock::now();
	 makeheap(v);
	 for (int i = v.size() - 1; i > 0; --i) {
	 	swap(v[0], v[i]);
	 	heapify(v, i, 0);
    }
	auto end = std::chrono::high_resolution_clock::now();
	printTime("heapSort", start, end);//检测时间	
}


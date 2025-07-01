#include <iostream>
#include <vector>
#include <chrono>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int sizes[] = {1000, 2000, 4000}; // Different input sizes
    for (int size : sizes) {
        std::vector<int> myArray(size);
        for (int i = 0; i < size; ++i) {
            myArray[i] = size - i; // Fill array in reverse order
        }
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(myArray);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Size: " << size << ", Time: " << duration.count() << " seconds" << std::endl;
    }
    return 0;
}

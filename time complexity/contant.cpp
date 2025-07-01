#include <iostream>
#include <vector>
#include <chrono>

int getFirstElement(const std::vector<int>& arr) {
    return arr[0];
}

int main() {
    int sizes[] = {1000000, 10000000, 100000000}; // Different input sizes
    for (int size : sizes) {
        std::vector<int> myArray(size, 1);
        auto start = std::chrono::high_resolution_clock::now();
        getFirstElement(myArray);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Size: " << size << ", Time: " << duration.count() << " seconds" << std::endl;
        // Consider additional constraints here if applicable
    }
    return 0;
}

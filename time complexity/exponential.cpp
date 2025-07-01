#include <iostream>
#include <chrono>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int sizes[] = {20, 25, 30}; // Different input sizes
    for (int size : sizes) {
        auto start = std::chrono::high_resolution_clock::now();
        fibonacci(size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "n: " << size << ", Time: " << duration.count() << " seconds" << std::endl;
    }
    return 0;
}

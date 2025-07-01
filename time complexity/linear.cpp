#include <iostream>
#include <vector>
#include <chrono>

void printElements(const std::vector<int> &arr)
{
    // for (int i : arr)
    // {
    //     std::cout << i << " ";
    // }
    std::cout << std::endl;
}

int main()
{
    int sizes[] = {100000, 200000, 400000}; // Different input sizes
    for (int size : sizes)
    {
        std::vector<int> myArray(size, 1);
        auto start = std::chrono::high_resolution_clock::now();
        printElements(myArray);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Size: " << size << ", Time: " << duration.count() << " seconds" << std::endl;
    }
    return 0;
}

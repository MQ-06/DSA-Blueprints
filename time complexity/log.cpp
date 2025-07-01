#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::iota
#include <chrono>

bool binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main()
{
    int sizes[] = {1000000, 10000000, 100000000}; // Different input sizes
    for (int size : sizes)
    {
        std::vector<int> myArray(size);
        std::iota(myArray.begin(), myArray.end(), 1); // Fill myArray with values 1 to size
        auto start = std::chrono::high_resolution_clock::now();
        binarySearch(myArray, size - 1); // Search for size - 1 (e.g., 999999, 9999999, 99999999)
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Size: " << size << ", Time: " << duration.count() << " seconds" << std::endl;
    }
    return 0;
}

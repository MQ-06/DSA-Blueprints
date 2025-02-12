#include "MaxHeap.cpp"
#include <iostream>
using namespace std;

int main()
{
    MaxHeap<int> maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(5);

    std::cout << "Max value: " << maxHeap.getMax() << std::endl;
    maxHeap.print_heap();

    maxHeap.deleteMax();
    std::cout << "Max value after deletion: " << maxHeap.getMax() << std::endl;
    maxHeap.print_heap();

    return 0;
}
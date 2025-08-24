#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
int main()
{
    // null pointer

    int *ptr = NULL;
    if (ptr == nullptr)
    {
        cout << "ptr is NULL\n";
    }

    int a = 10;
    ptr = &a;
    // or

    ptr = new int(1);

    cout << *ptr << endl;
    delete ptr;
    ptr = nullptr;

    // void pointer

    int num = 200;
    float num2 = 46.8;
    void *ptr2;

    ptr2 = &num;
    //here pointer points to int
    cout << "value of int num is: " << *(static_cast<int *>(ptr2)) << endl;
    ptr2=&num2;
    cout << "value of float num is: " << *(static_cast<float *>(ptr2)) << endl;
    return 0;
}
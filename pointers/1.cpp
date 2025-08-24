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
    // Pointer to an int
    int a = 10;
    int *ptr1 = &a;
    cout << "memory address " << ptr1 << endl;
    cout << "values:" << *ptr1 << endl;

    // pointer to a pointer
    int **ptr2 = &ptr1;
    cout << "address of ptr1: " << ptr2 << endl;       // value stored in ptr2 which is address of ptr1
    cout << "value stored in ptr2: " << *ptr2 << endl; // value stored in ptr1 which is address of a
    cout << "value stored in a: " << **ptr2 << endl;   // value stored in a


     **ptr2=5;
//    Pointer to a Pointer to a Pointer (A pointer to a pointer to a pointer is a variable that stores the address of a pointer that itself points to another pointer.)

    int ***ptr3 = &ptr2;
    cout << "address of ptr2: " << ptr3 << endl;
    cout << "value stored at ptr2: " << *ptr3 << endl;
    cout << "value stored at ptr1: " << **ptr3 << endl;
    cout << "value stored at a: " << ***ptr3 << endl;

    ***ptr3=1;
    cout<<a<<endl; //1

    return 0;
}
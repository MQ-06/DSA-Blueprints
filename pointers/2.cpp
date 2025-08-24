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
    // POINTER ARITHMETIC
    // incremented ( ++ )
    // decremented ( — )
    // an integer may be added to a pointer ( + or += )
    // an integer may be subtracted from a pointer ( – or -= )
    // difference between two pointers (p1-p2)

    int v[] = {1, 2, 3, 4, 5};
    int *ptr = v;
    cout << "base address of arr:" << ptr << endl;
    cout << "value at index 0:" << *ptr << endl;
    ptr++; // moves 4 bytes and goes to next index
    cout << "address of arr[1]:" << ptr << endl;
    cout << "value at index 1:" << *ptr << endl;

    // POINTER NOTATION FOR 1-D ARRAY (points to the first index of arr)

    int arr[] = {1, 2, 3, 4, 5};
    int *arr_ptr = arr;

    for (int i = 0; i < 5; i++)
    {
        cout << *(arr_ptr + i) << " ";
    }

    cout << endl;
    // POINTER NOTATION FOR 2-D ARRAY (points to the first row of arr)
    int two_arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*two_arr_ptr)[3] = two_arr; // it is a pointer that points to an arr of 3 elements of 1st row

    // two_arr_ptr=two_arr[0];
    // two_arr_ptr++;
    // now
    // two_arr_ptr=two_arr[1];
    // arr[0]: {1, 2, 3, 4}
    // arr[1]: {5, 6, 7, 8}
    // arr[2]: {9, 10, 11, 12}
    // cout << (*two_arr_ptr)[0]; // Access first element of first row: 1
    // cout << (*two_arr_ptr)[1]; // Access second element of first row: 2

    // cout << (*(two_arr_ptr + 1))[0]; // Access first element of second row: 5

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(*(two_arr_ptr + i) + j) << " ";
        }
        cout << endl;
    }

    //     *(*(ptr + i) + j):
    // ptr + i points to the i-th row of the array.
    // *(ptr + i) dereferences it to access the array corresponding to that row.
    // *(ptr + i) + j points to the j-th element in that row.
    // Finally, dereferencing that gives the value at position (i, j).

    // POINTER NOTATION FOR 3-D ARRAYS
    int three_arr[2][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}};
    int(*three_ptr)[3][3] = three_arr;
    // int (*three_ptr)[3][3] means three_ptr is a pointer that points to an array of 3 arrays, each containing 4 integers.
    cout << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << *(*(*(three_ptr + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
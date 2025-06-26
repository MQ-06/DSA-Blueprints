#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
// rotating an array k times

void rotate(int arr[], int size, int i)
{

    if (i >= size)
    {
        return;
    }
    int temp = arr[0];
    arr[i] = arr[i + 1];
    rotate(arr, size, i + 1);
    arr[size - 1] = temp;
}
void reverse_array(int arr[], int k, int size)
{
    if (k == 0)
        return;

    rotate(arr, size, 0);

    reverse_array(arr, k - 1, size);
}

void reverse(int *arr, int size, int l, int r)
{
    if (l >= r)
    {

        return;
    }
    swap(arr[l], arr[r]);
    reverse(arr, size, l + 1, r - 1);
}

void func(int *arr, int i, int size)
{
    if (i >= size / 2)
        return;
    swap(arr[i], arr[size - i - 1]);
    func(arr, i + 1, size);
}

// check if a string is palindrome or not
bool palindrome(string s, int i, int size)
{
    if(i>=size/2)return 1;
    if (s[i] != s[size - i - 1])
    {
        return false;
    }
   return palindrome(s, i + 1, size);
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    // reverse_array(arr, 3, 5);
    reverse(arr, 5, 0, 4);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
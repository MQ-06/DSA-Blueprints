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
    // count no of 1s in the binary representation of a number;
    int num = 2;
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1; // no right shift by 1
    }
    cout << count << endl;

    // check if a given numbr is a power of 2 or not

    int n = 8;

    if ((n & (n - 1)) == 0)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
cout<<endl;
    int a = 3;
    int b = 5;
    cout << "before swapping" << endl;
    cout << a << endl;
    cout << b << endl;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "after swapping" << endl;

    cout << a << endl;
    cout << b << endl;
    return 0;
}
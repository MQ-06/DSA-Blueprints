#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

void print(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    print(i + 1, n);
}

void reverse_print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    reverse_print(--n);
}

void f3(int N)
{
    if (N <= 1)
    {
        return ;
    }

    f3(N - 1);
    cout << N;
    f3(N - 1);
}
int main()
{
    // print from 1-n
    // print(1, 10);
    // cout << endl;
    // reverse_print(10);
    f3(4);
    return 0;
}
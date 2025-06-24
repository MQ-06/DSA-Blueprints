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

    // remove the last set bit(right most)
    int n = 16;

    cout << (n & (n - 1) )<< endl;
}
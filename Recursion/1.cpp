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
    if (i >= n)
    {
        return;
    }
    string s = "mariam";
    cout << s << endl;
    print(i + 1,n);
}
int main()
{
    print(0, 5);
    return 0;
}
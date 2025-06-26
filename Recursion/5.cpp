#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
void func(int x)
{
    if (x <= 0)
        return;
    cout << x ;
    func(x - 1);

    cout << x;
    func(x - 1);
    cout << x;
}
int main()
{
    func(4);

    return 0;
}
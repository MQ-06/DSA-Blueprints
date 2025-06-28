#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

struct Base
{
    int base;
    void show()
    {
        cout << "Base value: " << base << endl;
    }
};

struct Derived : public Base
{
    int derived;
    void show()
    {
        cout << "Base value: " << base << endl;

        cout << "Derived value: " << derived << endl;
    }
};
int main()
{
    Derived d;
    d.base = 10;
    d.derived = 15;
    d.show();
    return 0;
}
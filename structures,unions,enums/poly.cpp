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
    virtual void show()
    {
        cout << "Base" << endl;
    }
};

struct derived : public Base
{
    void show() override
    {
        cout << "Derived" << endl;
    }
};
int main()
{
    derived d;
    Base *b = &d;
    b->show();

    return 0;
}
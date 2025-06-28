#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
union myUnion
{
    // MyUnion can store either an int, float, or char, but only one at a time.
    int value;
    char ch;
    float num;
    // Constructor (only one member can be initialized)
    myUnion() {}
    myUnion(int v)
    {
        value = v;
    }
};

int main(){
// {Creates an instance of the union. Note that union members do not get automatically initialized; you should explicitly initialize them.


// Values are assigned to the union members. However, assigning a value to one member overwrites the previously assigned value. so only last assigned value will give accurate result others will show garbage
    myUnion un;
    un.value = 10;

    cout << "INT VALUE: " << un.value << endl;
    un.num = 3.14;
    cout << "Float value: " << un.num << endl;

    un.ch = 'A';
    cout << "Char value: " << un.ch << endl;

    // Note: Only the last assigned value is meaningful
    cout << "Int value (after assigning char): " << un.value << endl; //now it will show some random value

    return 0;
}
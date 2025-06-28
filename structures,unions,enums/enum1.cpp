#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
// Enums (short for enumerations) in C++ are a user-defined data type that consists of integral constants. They provide a way to name a set of integer values, which makes the code more readable and easier to manage.

enum Color
{
    RED,
    GREEN,
    BLUE
};
enum color
{
    // In this case, RED has the value 1, yellow has the value 3, and BLUE has the value 9.
    red = 1,
    yellow = 3,
    blue = 9
};
int main()
{

    enum Meal
    {
        breakfast,
        lunch,
        dinner
    };
    Meal m1 = breakfast;
    cout << m1 << endl;    // 0
    cout << RED << endl;   // 0
    cout << GREEN << endl; // 1
    cout << BLUE << endl;  // 2

    Color c = BLUE;
    if (c == BLUE)
    {
        cout << "color is blue";
    }
    cout<<endl;

    cout << red << endl; //prints 1
    cout << yellow << endl; //prints 3
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

enum class Meal
{
    breakfast,
    lunch,
    dinner
};

// Underlying Type
// This can be useful for controlling the storage size of the enum or ensuring compatibility with other code.
enum class Color:unsigned int{
       RED,
    GREEN,
    BLUE
};

int main()
{
    Meal meal = Meal::lunch;
    if (meal == Meal::lunch)
    {
        cout << "lunch time" << endl;
    }
    return 0;
}
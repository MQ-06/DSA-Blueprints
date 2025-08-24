#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
    // template based array class in c++
    array<int, 3> arr1 = {1, 2, 3};
    const int cols = 3;
    const int rows = 2;
    const int depth = 1;
    array<array<int, 4>, 3> arr2 = {// Declaration and initialization
                                   {{1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12}}};

    array<array<array<int, 4>, 3>, 2> arr = {  // Declaration and initialization
        {{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }}
    };

    for (const auto& matrix : arr) {
        for (const auto& row : matrix) {
            for (const auto& val : row) {
                cout << val << " "; // Outputs: 1 to 24
            }
        }
    }
    return 0;
}
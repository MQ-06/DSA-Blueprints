#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <set>
using namespace std;

int main()
{

    // by default sets are printed in ascending order

    // to get it printed in descending order

    // greater<int> is a functor

    set<int, greater<int>> s1 = {1, 2, 7, 8, 9, 10, 1};
    set<int, greater<int>>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
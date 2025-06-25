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
    // given n strings print unique string only

    vector<char> v = {'a', 'a', 'b', 'z', 'c', 'w', 'i', 'a', 'b', 'f', 'z'}; // have duplicated characters so we will use only a char set to store unique characters(in order).
    // aggr unique characters ke sath unki frequency store krni hoti in order to map
    set<char> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    for (char value : s)
    {
        // will print unique characters only in the vector
        cout << value << " ";
    }
}
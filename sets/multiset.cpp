#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{

    multiset<string> s;

    s.insert("abc");
    s.insert("abc");
    s.insert("bda");
    s.insert("abd");
    s.insert("zxc");

    for (string value : s)
    {
        cout << value << endl; // all values including duplicates will be printed in ascending order.
    }

    auto it = s.find("abc");
    s.erase(it); // deletes only 1st occurence of this value

    // but it
    s.erase("abc"); // deletes all occurences of abc

    unordered_set<int> st = {3, 4, 5, 2, 4, 4};
    // will be printed randomly
    for (int value : st)
    {
        cout << value << endl; // all values including duplicates will be printed in ascending order.
    }
}
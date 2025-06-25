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
    set<string> s; // default set is ordered set will print values in sorted order

    // can insert values by insert method only

    s.insert("A");
    s.insert("B");
    s.insert("b");
    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("abc");
    s.insert("xyz");
    // to find a value in a set (find)
    auto it = s.find("a");
    if (it != s.end())
    {
        cout << (*it) << endl;
    }
    else
    {
        cout << "value in a set not found" << endl;
    }

    s.erase("l");

    for (string value : s)
    {
        cout << value << " ";
    }
    cout << endl;
    // for (set<string>::iterator it = s.begin(); it != s.end(); it++)
    // {
    //     cout << (*it) << endl;
    // }

    int i = s.count("a");
    cout << i << endl;

    return 0;
}
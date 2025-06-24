#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <map> //default map is ordered map(sorted in increasing order of key values)
using namespace std;

// FIND FREQUENCY OF STRING
int main()
{
    int t = 8;
    vector<string> v = {"abc", "def", "abc", "def", "def", "cda"};

    map<string, int> mp;
    mp["def"] = 4;
    cout << mp["def"] << endl; //4
    cout << mp["abc"] << endl; // it returns 0(value) bcz it is not in the map
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++; // for first iteration mp["abc"]++=m["abc"]=1
    }

    for (auto &pr : mp)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
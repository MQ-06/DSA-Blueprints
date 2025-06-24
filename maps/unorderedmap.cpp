#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <unordered_map> //default map is ordered map(sorted in increasing order of key values)
using namespace std;

int main()
{
    unordered_map<int, int> mp;
    vector<int> v = {1, 2, 3, 4, 1, 1, 1, 2, 5, 3, 2, 6, 9, 8, 5, 4, 2, 1, 45, 7};

    vector<int>::iterator it = v.begin();

    while (it != v.end())
    {
        mp[(*it)]++;
        it++;
    }
    // will be printed randomly (not in ascending sorted order) based on their hash value
    for (auto &pr : mp)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
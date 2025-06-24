#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    // by default its an ordered map (we can also declare unordered_map)
    multimap<int, string> mp;

    mp.insert({1, "A"});
    mp.insert({2, "B"});
    mp.insert({1, "C"});
    mp.insert({3, "D"});
    mp.insert({4, "R"});
    mp.insert({1, "E"});
    mp.insert({2, "T"});
    mp.insert({6, "Y"});
    // will be printed in increasing order of keys
    for (auto &pr : mp)
    {
        cout << pr.first << " " << pr.second << endl;
    }

    unordered_multimap<int, string> unmp;
cout<<endl;
    unmp.insert({1, "A"});
    unmp.insert({2, "B"});
    unmp.insert({1, "C"});
    unmp.insert({3, "D"});
    unmp.insert({4, "R"});
    unmp.insert({1, "E"});
    unmp.insert({2, "T"});
    unmp.insert({6, "Y"});

    //printed in random order
     for (auto &pr : unmp)
    {
        cout << pr.first << " " << pr.second << endl;
    }

}
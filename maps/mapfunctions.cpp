#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <map> //default map is ordered map(sorted in increasing order of key values)
using namespace std;

int main()
{
    // here can be vectors,sets etc
    map<int, string> mp;

    mp[1] = "A";
    mp[2] = "B";
    mp[4] = "D";
    mp[3] = "C";
    // find an element(key)
    auto it = mp.find(1);
    if (it != mp.end())
    {
        cout << "Doesnt exitst";
    }
    else
    {
        cout << it->first << " " << it->second << endl;
    }
    // erase an element(with iterator/key)
    mp.erase(1);
    auto it2 = mp.find(1);
    mp.erase(it2);

    mp.size();  // current no of pairs in the map
    mp.clear(); // map becomes empty

    cout << mp.at(2) << endl; //returns value associated with that key
    
}
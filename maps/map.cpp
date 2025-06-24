#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <map> //default map is ordered map(sorted in increasing order of key values)
using namespace std;
void printmap(map<int, string> &m)
{
    auto it = m.begin();
    while (it != m.end())
    {
        cout << (*it).first << " " << (*it).second << endl;
        it++;
    }

    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
int main()
{

    map<int, string> m;
    m[3] = "mariam";
    m[2] = "rahat";
    m[4] = "umer";
    m[1] = "ramsha";

    map<int, string>::iterator it;
    cout << "size of map(no of pairs): " << m.size() << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    m.insert({0, "father"});
    printmap(m);

    return 0;
}
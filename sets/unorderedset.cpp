#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <unordered_set> //used when order doesnt needed and to search if a value exits or not
using namespace std;

int main()
{

    unordered_set<int> s = {1, 2, 3, 4, 1, 2, 3, 3};

    auto it = s.find(10);
    if (it != s.end())
    {
        cout << "value find at address" << *(it) << endl;
    }
    else
    {
        cout << "value not found";
    }
}
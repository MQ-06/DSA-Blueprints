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
    set<int> st = {1, 2, 4, 4, 1, 2, 6, 7, 8, 9};
    cout << "Size of set: " << st.size() << endl;//only have 7 unique elements so size 7 rest values ignored

    auto it = st.lower_bound(1);  // will give 1
    auto it2 = st.upper_bound(1); // will give 2

    cout << "Lower bound value: " << (*it) << endl;
    cout << "Upper bound value: " << (*it2) << endl;

    for (auto it = st.begin(); it != st.end(); ++it)
    {
        int count = st.count(*it);
        cout << count << endl; // will be 1 for all element
    }
}
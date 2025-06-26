#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

void subsequences(vector<int> &v, int index, vector<int> &ans)
{
    if (index == v.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << "";
        }

        if (ans.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        
        return;
    }

    ans.push_back(v[index]); // take
    subsequences(v, index + 1, ans);
    ans.pop_back(); // not take
    subsequences(v, index + 1, ans);

}
int main()
{
    vector<int> v = {1, 2};
    vector<int> sol;
    subsequences(v, 0, sol);

    return 0;
}
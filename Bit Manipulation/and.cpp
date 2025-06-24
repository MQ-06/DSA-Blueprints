#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <bitset>
using namespace std;
void printBinary(int num)
{
    cout << bitset<32>(num);
}
int main()
{
    int x = 5;
    int y = 3;
    cout << "Binary representation of x: " << endl;
    printBinary(x);

    cout << "Binary representation of y: " << endl;
    printBinary(y);
    cout<<endl;
    cout << "and: " << (x & y) << endl;
    cout << "or: " << (x | y) << endl;
    cout << "XOR: " << (x ^ y) << endl;
    cout << "NOT: " << ~(x) << endl;

    return 0;
}
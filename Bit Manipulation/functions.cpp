#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <bitset>
using namespace std;

void printbinary(int num)
{

    cout << bitset<32>(num) << endl;
}
// get the ith bit in the no
bool getBit(int num, int i)
{

    return ((num & (1 << i)) != 0); // returns true if at ith position the bit is 1 (means set
}
// set the ith bit in the num to 1
int setBit(int num, int i)
{

    return (num |= (1 << i)); // returns the same number but with bit set to 1 at ith position
}
// set the ith bit in the num to 0
int clearBit(int num, int i)
{

    return num &= (~(1 << i)); // returns the same number but with bit set to 0 at ith position
}

int toggle_filebit(int num, int i)
{

    return (num ^= 1 << i); // return the same number with toggled bit at ith position
}
int main()
{
    int N = 70;

    cout << "binary representation of number =70 ";
    printbinary(N);
    cout << "The bit at the 3rd position from LSB is: "
         << (getBit(N, 3) ? '1' : '0')
         << endl;

    cout << "The value of the given number "
         << "after setting the bit at "
         << "LSB is: "
         << setBit(N, 0) << endl;

    cout << "The value of the given number "
         << "after clearing the bit at "
         << "LSB is: "
         << clearBit(N, 0) << endl;

    cout << "The value of the given number "
         << "after TOGGLING the bit at "
         << "LSB is: "
         << toggle_filebit(N, 3) << endl;
}
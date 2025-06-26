#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

void TOH(int disk, char A, char B, char C)
{
    if (disk == 1)
    {
        cout << "Disk " << disk << " moved from  " << A << " to " << C << endl;
        return;
    }
    TOH(disk - 1, A, C, B);
    cout << "Disk " << disk << " moved from  " << A << " to " << C << endl;
    TOH(disk - 1, B, A, C);
}
int main()
{

    TOH(10, 'A', 'B', 'C');

    return 0;
}
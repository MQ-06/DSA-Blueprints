#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;
int main()
{
    int *ptr = new int[5];

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i;
        *(ptr+i)=i+1;
    }
    for(int i=0;i<5;i++){
        cout<<ptr[i]<<" ";
    }
    return 0;
}
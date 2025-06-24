#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdexcept>
#include<limits>
#include<algorithm>
using namespace std;
int main(){
char s[10] = "BCSFall19"; 
cout << (s + 3)[5] << endl; 
 int a = 10, b = ++a, c = b++; 
    cout << a << " " << b << " " << c << endl;   
return 0;
}
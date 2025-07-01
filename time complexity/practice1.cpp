#include<stdio.h>
void func(int n)
{
    int sum=0;  //1
    int product =1;//1
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)// n*n
        {
            printf("%d , %d\n", i,j);
        }
    }
    // O(N^2)
}

void func1(int array[], int length)
{
    int sum=0;//1
    int product =1;//1
    for (int i = 0; i <length; i++)
    {
        sum+=array[i];//length
    }
 
    for (int i = 0; i < length; i++)
    {
        product*=array[i];//length
    }
}
 
int main()
{
    int arr[] = {3,4,66};//1
    func1(arr,3);//1

//    1+2+3(length)+4(length)+5+6
//    length(3+4)
//    length
    return 0;
}


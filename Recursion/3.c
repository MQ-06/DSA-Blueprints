#include<stdio.h>

void fun(int x) {
    if (x > 0) {
        fun(x - 1);
        printf("%d", x);
        fun(x - 1);
    }
}

int main() {
    int n = 3;
    fun(n);//1213121
    return 0;
}

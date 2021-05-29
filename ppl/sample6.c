#include<stdio.h>

void recursion(int n){
    if(n <= 0) return ;
    printf("%d\n",n);
    recursion(n-1);
}

int main() {
    int n = 5;
    recursion(n);
    return 0;
}
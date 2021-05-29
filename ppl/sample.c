#include<stdio.h>

//sample program

int add(int p,int q,int r){
    int ans  = p+q+r;
    return ans;
}

int main()
{
   int x = 5,y = 3,z = 4;
   int ans = add(x,y,z);
   printf("%d",ans);
}
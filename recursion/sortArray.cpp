#include<bits/stdc++.h>
using namespace std;

void insertSort(int arr[],int n,int pop){
    if(n == 0){
        arr[n] = pop;
        return ;
    }
    if(arr[n-1] > pop){
        int p = arr[n-1];
        insertSort(arr,n-1,pop);
        arr[n] = p;
        return ;
    }
    else{
        arr[n] = pop;
        return ;
    }
}

void recurSort(int arr[],int n){
     if(n == 1){
         return ;
     }
     int pop = arr[n-1];
     recurSort(arr,n-1);
     insertSort(arr,n-1,pop);
     return ;
}

int main() {
    int arr[] = {2,4,39,4,6,9,8};
    recurSort(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int range;
    cin>>range;
    int a[range];
    for(int i=0;i<=range;i++){
        a[i] = 0;
    }
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    for(int i=0;i<=range;i++){
        
           while(a[i]!=0){
               cout<<i<<" ";
               a[i]--;
           }
        
    } 
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int mn = n+1;
        int brr[n];

        for(int i=(n);i>0;i--){
            mn = min(mn,i-arr[i-1]);
            // cout<<mn<<" ";
            if(i>mn){
                brr[i-1] = 1;
            }
            else{
                brr[i-1] = 0;
            }
        }
        for(int i=0;i<n;i++){
            cout<<brr[i]<<" ";
        }
        cout<<'\n';
    }
}


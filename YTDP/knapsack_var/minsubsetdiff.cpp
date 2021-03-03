// problem given array no
//find minm diff b/w two subset sum form by it.

// so basically let say arr sum is s
// then s = s1+s2; where ans = abs(s2-s1).
// so, ans = s-2s1
// thus need to have maximize s1.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,sum =0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int s = sum/2;
    bool dp[n+1][s+1];
    //Intialsiation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(int i=s;i>=0;i--){
        if(dp[n][i]){
            cout<<(sum-2*i);
            break;
        }
    }
}
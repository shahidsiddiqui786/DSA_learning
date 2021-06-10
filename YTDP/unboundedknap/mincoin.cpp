#include<bits/stdc++.h>
using namespace std;

//problem statemant


int main(){
    int sum,n;
    cin>>sum>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                dp[i][j] = INT_MAX-1;
            }
            if(j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int j=1;j<=sum;j++){
        if(j%arr[0] == 0){
            dp[1][j] = j/arr[0];
        }
        else{
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= arr[i-1]){
                dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}
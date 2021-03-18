/*
  problem::::-----
      Given a sum of money you need get a bunch of coins in exchage of it.
      an array is given of availbale coins, you need to find no of ways 
      to exchange the money.
  
  Solution::::----
    consider sum as s and set of coins, a1,a2,a3,a4..,
    so, we have sub problem here sum-a1 as sum and 
    coins as given coins.

    so, approaced as DP.

*/

#include<bits/stdc++.h>
using namespace std;

// int coinways(int arr[],int n,int sum){
//     if(n == 0){
//         return 0;
//     }
//     if(sum == 0){
//           return 1;
//        } 
//     if(arr[n-1] <= sum){
//         return coinways(arr,n,sum-arr[n-1])+coinways(arr,n,sum);
//     }
//     else{
//         return coinways(arr,n-1,sum);
//     }
// }

int main(){
    int sum,n;
    cin>>sum>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n+1][sum+1];
    // cout<<coinways(arr,n,sum);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i][j-arr[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}
// problem given array no
//  given a sum , find how many subset are there that exist thru some of array no

/* recur approach
    int subsetsum(int arr[],int sum,int n){
       if(sum == 0){
           return 1;
       }
       if(n == 0){
           return 0;
       }
       if(arr[n-1] <= sum){
         return (subsetsum(arr,sum-arr[n-1],n-1) + subsetsum(arr,sum,n-1));
       }
       return subsetsum(arr,sum,n-1);
   }
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n+1][sum+1];
    //Intialsiation
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
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}
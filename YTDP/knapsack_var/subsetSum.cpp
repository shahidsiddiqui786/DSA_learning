// problem given array no
//  given a sum is that exist thru some of array no

/* recur approach
   bool subsetsum(int arr[],int sum,int n){
       if(sum == 0){
           return true;
       }
       if(n == 0){
           return false;
       }
       if(arr[n-1] <= sum){
         return (subsetsum(arr,sum-arr[n-1],n-1) || subsetsum(arr,sum,n-1));
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
    bool dp[n+1][sum+1];
    //Intialsiation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
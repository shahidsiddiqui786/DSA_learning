// problem given array no
// just need to divide into two parts such that
  // their sum are equals

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
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
   if(sum & 1){
       cout<<"NO";
   }
   else{
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
                    dp[i][j] = (dp[i-1][s-arr[i-1]] || dp[i-1][s]);
                }
                else{
                    dp[i][j] = dp[i-1][s];
                }
            }
        }
        if(dp[n][s]){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
   }
}
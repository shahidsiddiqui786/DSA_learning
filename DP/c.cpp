// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

/*  
  DP:- Dynamic prog. is like divide and conquer and plus point 
  we remember the previous things as memorization in some data 
  str. .
  So, basically things recursive solution first if prb appears 
  to be Dp:
  .then (
      have two way either do memoziation or top down approach.
  )
*/

// knapsack 0/1 prb.
/* prb is that u have been given a list of wts of objects and their respective 
   price you have to carry maximum prize objects without breaking and every object
   is single in a bag of Wt W.*/

// memoziatison

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,W;
    int dp[n+1][W+1];
    cin>>n;
    int arr[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cin>>W;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
             if(j == 0 || i == 0){
                 dp[i][j] = 0;
             }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
             
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(val[i-1]+dp[i-1][j-arr[i-1]], dp[i-1][j])
            }
        }
    }

    return 0;
}

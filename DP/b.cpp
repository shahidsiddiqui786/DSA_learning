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


int dp[1000][1000];



int RecApprch(int wt[], int val[], int W, int n) {
    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }
    
    if(wt[n-1] > W){
       return dp[n][W] = RecApprch(wt, val, W, n-1);
    }
    else{
       return dp[n][W] = max(val[n-1]+RecApprch(wt, val, W-wt[n-1], n-1), RecApprch(wt, val, W, n-1));
    }
}

int main()
{
    int n,W;
    memset(dp,-1,sizeof(dp));
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
    cout<<RecApprch(arr,val,W,n);

    return 0;
}

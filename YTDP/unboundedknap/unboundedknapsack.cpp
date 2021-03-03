// problem :- 
// unbounded have a infinte availability.
//      Given a W capacity bag
//      Need to put some wts into it from a array given with their some value
//      Task is to maximize the total value put in bag.
//      So, as there is choice and decision attribute,
//      thus recur can be a good approach.
    // Problem
    //   wt[] = {3,5,7,1,9,4}
    //   val[] = {6,90,1,34,23,34}
    //   W = 17

/*    //solution using recursion
    int knapsack(int wt[],int val[],int W, int n){
        //if 0 capacity or no wt given then 0 value.
        if(n == 0 || W == 0){
            return 0;
        }
        //can only take current obj if it is less or = than W
        if(wt[n-1] <= W){
            // either take current object or leave it, cons. we need max of both
            return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n),knapsack(wt,val,W,n-1));
        }
        return knapsack(wt,val,W,n-1);
    }
*/

 // So , the a lot recursion creates problems for large values
 // thus, switch to DP(rembeber what you have calc. already)

 //DP(Memoization)

/*  Declare a global array according max constraint
    like say W <= 1000, n <= 1000
    int DP[1000][1000] ={-1};
   //solution using recursion
    int knapsack(int wt[],int val[],int W, int n){
        //if 0 capacity or no wt given then 0 value.
        if(n == 0 || W == 0){
            return 0;
        }
        if(DP[n][W] != -1){
            return DP[n][W];
        }
        //can only take current obj if it is less or = than W
        if(wt[n-1] <= W){
            // either take current object or leave it, cons. we need max of both
            return DP[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n),knapsack(wt,val,W,n-1));
        }
        return DP[n][W] = knapsack(wt,val,W,n-1);
    }
*/

//Now top-down approach (DP)
#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int n,W;
    cin>>n>>W;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int dp[n+1][W+1];
    // Intialsiation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
           if(wt[i-1]<=j){
              dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
           }
           else{
              dp[i][j] = dp[i-1][j];
           }
        }
    }
    cout<<dp[n][W]<<" ";
}

    


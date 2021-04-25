// problem :- 
// Given a rod need to cut in pieces and for every 
 // pieces there is a prize given in array
 // purpose is to maximize the total prize of cutted rods.
    // Problem
    //   price[] = {6,90,1,34,23,34}
    //   len[] = {1,2,3,4,5,6}
    //   length ,l = 6

/*    //solution using recursion
    int knapsack(int len[],int price[],int l, int n){
        //if 0 capacity or no wt given then 0 value.
        if(n == 0 || l == 0){
            return 0;
        }
        // either cut it for current size or leave it.
        return max(price[n-1]+knapsack(len,price,l-len[n-1],n),knapsack(len,price,l,n-1));
    }
*/

 // So , the a lot recursion creates problems for large values
 // thus, switch to DP(rembeber what you have calc. already)

 //DP(Memoization)

/*  Declare a global array according max constraint
    like say l <= 1000, n <= 1000
    int DP[1000][1000] ={-1};
   //solution using recursion
    int knapsack(int wt[],int val[],int W, int n){
        //if 0 capacity or no wt given then 0 value.
        if(n == 0 || l == 0){
            return 0;
        }
        if(DP[n][W] != -1){
            return DP[n][W];
        }
         // either cut it for current size or leave it.
        return max(price[n-1]+knapsack(len,price,l-len[n-1],n),knapsack(len,price,l,n-1));
    }
*/

//Now top-down approach (DP)
#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int n,l;
    cin>>n>>l;
    int len[n],price[n];
    for(int i=1;i<=n;i++){
        len[i] = i;
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int dp[n+1][l+1];
    // Intialsiation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=l;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=l;j++){
           dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
        }
    }
    cout<<dp[n][l]<<" ";
}

    


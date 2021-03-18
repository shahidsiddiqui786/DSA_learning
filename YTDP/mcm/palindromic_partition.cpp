//matrix chain multiplication optimal operation
#include<bits/stdc++.h>
using namespace std;

// ispalindrome
bool ispalindrome(string str,int i, int j){
    if(i >= j) return true;
    if(str[i] == str[j]){
        return ispalindrome(str,i+1,j-1);
    }
    else{
        return false;
    }
}

//recursive appproach

// int minpart(string str, int i, int j){
//      if(i == j) return 0;
//      if(ispalindrome(str,i,j)) return 0;

//      int mina = INT_MAX;

//      for(int k = i;k<j;k++){
//          int temp = minpart(str,i,k)+minpart(str,k+1,j)+1;
//          mina = min(mina,temp);
//      }
//      return mina;
// }

//memoization approach
int dp[1000][1000];

// int minpart(string str, int i, int j){
//      if(i == j) return 0;
//      if(ispalindrome(str,i,j)) return 0;

//      if(dp[i][j] != -1){
//          return dp[i][j];
//      }

//      int mina = INT_MAX;

//      for(int k = i;k<j;k++){
//          int temp = minpart(str,i,k)+minpart(str,k+1,j)+1;
//          mina = min(mina,temp);
//      }
//      return dp[i][j] = mina;
// }

//more optimised version in memoization
int minpart(string str, int i, int j){
     if(i == j) return 0;
     if(ispalindrome(str,i,j)) return 0;

     if(dp[i][j] != -1){
         return dp[i][j];
     }

     int mina = INT_MAX;

     for(int k = i;k<j;k++){
         int temp,left,right;
         if(dp[i][k] == -1){
             dp[i][k] = minpart(str,i,k);
         }

         if(dp[k+1][j] == -1){
            dp[k+1][j] = minpart(str,k+1,j);
         }

         temp = dp[i][k] + dp[k+1][j] +1;

         mina = min(mina,temp);
     }
     return dp[i][j] = mina;
}


int main(){
    
    string str;
    cin>>str;
    int n = str.length();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout<<minpart(str,0,n-1);
} 


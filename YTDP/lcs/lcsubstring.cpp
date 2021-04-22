#include<bits/stdc++.h>
using namespace std;
// LCSubstring Problem Statement: Given two strings, find the length of 
// longest substring present in both of them. A substring is a 
// sequence that appears in the same relative order, but not
// necessarily contiguous. 

//Recursive approach
/*
int lcs(string a,string b,int n,int m,int maxp){
     if(n == 0 || m == 0){
         return maxp;
     }
     if(a[n-1] == b[m-1]){
        maxp = lcs(a,b,n-1,m-1,maxp+1);
     }
         return max(maxp,max(lcs(a,b,n-1,m,0), lcs(a,b,n,m-1,0)));
}
*/

int main() {
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    
    // cout<<lcs(a,b,n,m,0);

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            if(i>0 && j>0){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                   dp[i][j] = 0;
                }
            }
        }
    }
    int maxp = 0;
     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
           if(dp[i][j] > maxp){
               maxp = dp[i][j];
           }
        }
    }

    cout<<maxp;
}
#include<bits/stdc++.h>
using namespace std;
// LCS Problem Statement: Given two sequences, find the length of 
// longest subsequence present in both of them. A subsequence is a 
// sequence that appears in the same relative order, but not
//  necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”,
//   ‘”acefg”, .. etc are subsequences of “abcdefg”.

//Recursive approach
/*
int lcs(string a,string b,int n,int m){
     if(n == 0 || m == 0){
         return 0;
     }
     if(a[n-1] == b[m-1]){
         return 1+lcs(a,b,n-1,m-1);
     }
     else{
         return max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
     }
}
*/

int main() {
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    
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
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j];
        }
        cout<<'\n';
    }

    cout<<dp[n][m];
}
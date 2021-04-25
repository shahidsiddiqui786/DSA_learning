#include<bits/stdc++.h>
using namespace std;
// LCS Problem Statement: Given two sequences, find the length of 
// longest subsequence present in both of them. A subsequence is a 
// sequence that appears in the same relative order, but not
//  necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”,
//   ‘”acefg”, .. etc are subsequences of “abcdefg”.



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
    
    string op;
    int j = m, i = n;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            op.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
               j--;
            }
        }
    }

    string ap;
    for(int i=op.length()-1;i>=0;i--)
        ap.push_back(op[i]);
    
    cout<<ap;
}
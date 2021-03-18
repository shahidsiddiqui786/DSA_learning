#include<bits/stdc++.h>
using namespace std;
// Given a string, find the length of the longest repeating subsequence such that
// the two subsequences don’t have same string character at the same position,
// i.e., any i’th character in the two subsequences shouldn’t have the same index
// in the original string.


int main() {
    string a,b;
    cin>>a;
    int n = a.length();
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            if(i>0 && j>0){
                if(a[i-1] == a[j-1] && i != j){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    
    cout<<dp[n][n];
}
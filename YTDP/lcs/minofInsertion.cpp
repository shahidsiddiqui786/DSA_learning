#include<bits/stdc++.h>
using namespace std;
// find minimum no of insertion in a string to make it a palindrome.

// clearly , we can see In deletion problem we are deleting string-lcs
// letter to make it palindrome, so now this time we need not to 
// delete them instead we need to insert the similar element to make 
// it paired and so that  it make whole string a palindrome.
//so, ans will be same

int main() {
    string a,b;
    cin>>a;
    b = a;
    reverse(a.begin(),a.end());
    int n = a.length();
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
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
    
    cout<<n - dp[n][n];
}
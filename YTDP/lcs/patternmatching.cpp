#include<bits/stdc++.h>
using namespace std;
// given a pattern as a string a, and a string b,
// find given pattern is present in b or not.

//recursive
// bool rec(string a,string b,int n,int m){
//     if(n == 0) return true;
//     if(m == 0) return false;
//     if(a[n-1] == b[m-1]) return rec(a,b,n-1,m-1);
//     return rec(a,b,n,m-1);
// }

int main() {
    string a,b;
    cin>>a>>b;
    
    int n = a.length();
    int m = b.length();

    //cout<<rec(a,b,n,m)<<'\n';
    
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

   

    if(dp[n][m] == n){
        cout<<"yes"<<'\n';
    }
    else{
        cout<<"no"<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
// need to find the minumum no of Insertion and deletion is needed in the
// string a to convert it Into string b.

//solution :- so just find out lcs of two string a and b,
// and u are good to go! , clearly you can see letter other than
// lcs letters in a are need to be deleted and , in b are need to be
// required inserted letters.


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
    
    cout<<"Min no of insertion "<<m-dp[n][m];
    cout<<"\nMin no of Deletion "<<n-dp[n][m];
    
}
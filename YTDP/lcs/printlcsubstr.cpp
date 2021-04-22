#include<bits/stdc++.h>
using namespace std;


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
                   dp[i][j] = 0;
                }
            }
        }
    }

     int maxp = 0,k;
     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
           if(dp[i][j] > maxp){
               maxp = dp[i][j];
               k = i;
           }
        }
     }
    
    string op;
    while(maxp!=0){
        op.push_back(a[k-1]);
        k--;
        maxp--;
    }

    string ap;
    for(int i=op.length()-1;i>=0;i--)
        ap.push_back(op[i]);
    
    cout<<ap;
}
#include<bits/stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[10][10];

int tsp(int mask,int pos){
     if(mask == ((1<<n)-1)){
          return dist[pos][0];
     }
      

     if(dp[mask][pos] != -1){
         return dp[mask][pos];
     }  

     int ans = INT_MAX ; 

     for(int city=0;city<n;city++){
         if((mask&(1<<city)) == 0){

             int newans = dist[pos][city] + tsp(mask | (1<<city), city);
             ans = min(ans,newans);

         }
     } 

     return dp[mask][pos] = ans;
}

int main(){

    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            dp[i][j] = -1;
        }
    }

    cout<<tsp(1,0)<<'\n';
    return 0;
}
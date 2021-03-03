#include<bits/stdc++.h>
using namespace std;


// bool issubset(vector<int> v, vector<int> val, int n, int w){
//        if(w ==  0){
//            return true;
//        }
//        if(n == 0){
//            return false;
//        }
//        if(v[n-1] <= w){
//          return  issubset(v,val,n,w-n) || issubset(v,val,n-1,w);
//        }
//        return issubset(v,val,n-1,w);
// }

// int apple(vector<int> v, vector<int> val, int n, int w){
//     if(w == 0){
//         return 0;
//     }
//     if(n == 0){
//         return INT_MAX;
//     }

//     if(v[n-1] <= w){
//          return min(val[n-1]+apple(v,val,n,w-n),apple(v,val,n-1,w));
//     }

//     return apple(v,val,n-1,w);
// }


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int arr[n];
        vector<int> v;
        vector<int> val;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] != -1){
                v.push_back(i+1);
                val.push_back(arr[i]);
            }
        }
        int size = v.size();
        bool dp1[size+1][w+1];
        for(int i=0;i<=size;i++){
            for(int j=0;j<=w;j++){
                if(j == 0){
                    dp1[i][j] = 1;
                }
                if(i == 0){
                    dp1[i][j] = 0;
                }
            }
        }

        for(int i=1;i<=size;i++){
            for(int j=1;j<=w;j++){
                if(v[i-1] <= j){
                    dp1[i][j] = dp1[i][j-i] || dp1[i-1][j];
                }
                else{
                    dp1[i][j] = dp1[i-1][j];
                }
            }
        }

        if(dp1[size][w]){
            int dp[size+1][w+1];
            for(int i=0;i<=size;i++){
                    for(int j=0;j<=w;j++){
                        if(i == 0){
                            dp[i][j] = INT_MAX;
                        }
                        if(j == 0){
                            dp[i][j] = 0;
                        }
                    }
                }

                for(int i=1;i<=size;i++){
                    for(int j=1;j<=w;j++){
                        if(v[i-1] <= j){
                            dp[i][j] = min(val[i-1]+dp[i][j-i] ,dp[i-1][j]);
                        }
                        else{
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
            cout<<dp[size][w]<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
        v.clear();
        val.clear();
    }
}
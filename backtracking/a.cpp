#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k1,k2;
        cin>>n>>k1>>k2;
        int w,b;
        cin>>w>>b;
        if((w+b) <= n){
            int ctw = min(k1,k2) + (max(k1,k2)-min(k1,k2))/2;
            int ctb = n - max(k1,k2) + (max(k1,k2)-min(k1,k2))/2;
            // cout<<ctw<<" "<<ctb;
            if(ctw >= w && ctb >= b){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}
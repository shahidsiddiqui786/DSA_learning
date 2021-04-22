#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
     int t;
     cin>>t;
     while(t--){
         ll n,k;
         cin>>n>>k;
         ll sz = n*k;
         vector<ll> v(sz);
         for(ll i=0;i<sz;i++){
             cin>>v[i];
         }
         //greed is to maximize individual median
         int greedPosition = 0;
         if(n & 1) greedPosition = (n/2)+1;
         else greedPosition = (n/2);

        int i=1,j=sz;
        ll median = 0;
        
        do{
            i += (greedPosition-1);
            j = j - (n-greedPosition);
            median += v[j-1];
            j--;
        }while(i<=j);
        cout<<median<<'\n';
     }
}
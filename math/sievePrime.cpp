#include<iostream>
#include<vector>
using namespace std;

vector<int> sieve(int n){
    vector<int> v(n,1);
    int p =2;
    while(p<n){
        if(v[p]==1){
            int i=0;
            while((p*(p+i))<n){
            v[p*(p+i)] = 0;
            i++;
            }
        }
        p++;
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    v = sieve(n);
    for(int i=2;i<n;i++){
       if(v[i]==1){
           cout<<i<<" ";
       }
    }
}
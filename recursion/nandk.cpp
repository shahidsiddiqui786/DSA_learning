#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    if(n == 1){
        return 0;
    }
    if(k & 1){
        int pk = (k+1)/2;
        int a = solve(n-1,pk);
        return a;
    }
    else{
        int pk = k/2;
        int a = solve(n-1,pk);
        if(a == 1){
            return 0;
        }
        else{
            return 1;
        }
    }
}


int main() {
    
    cout<<solve(1200,602);
}
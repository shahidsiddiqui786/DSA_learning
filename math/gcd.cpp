#include<iostream>
#include<vector>
using namespace std;

int gcd(int n,int m){
    if(n == 0){
        return m;
    }
    return gcd(m%n, n);
}

int lcm(int n,int m){
    return (n*m)/gcd(n,m);
}


int main(){
    int n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
    cout<<'\n'<<lcm(n,m);
}
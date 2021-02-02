#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int n;
    cin>>n;
    int sum = 0;
    int f = 5;
    while(f<n){
        sum += floor(n/f);
        f*=5;
    }
    cout<<sum;
}
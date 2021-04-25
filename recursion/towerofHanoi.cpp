#include<bits/stdc++.h>
using namespace std;

void towerofHanoi(int n,int a,int b,int c){
    if(n>0){
        towerofHanoi(n-1,a,c,b);
        cout<<"Move a Disc from"<<a<<" to "<<c<<'\n';
        towerofHanoi(n-1,b,a,c);
    }
}

int main(){
    int n;
    cin>>n;
    towerofHanoi(n,1,2,3);
}
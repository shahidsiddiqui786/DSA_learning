// The following is a description of the instance of this famous puzzle involving
//  n eggs and a building with k floors.Need to find max floor on which egg drops doesn't
//  broke using the only given n eggs.The problem is not actually to find the critical 
//floor, but merely to decide floors from which eggs should be dropped so that the total
// number of trials are minimized.

#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e,int f){
    if(f == 0 || f == 1){
        return f;
    }
    if(e == 1){
        return f;
    }

    int mina = INT_MAX;
    for(int i=1;i<=f;i++){
       int temp = 1+ max(eggDrop(e-1,i-1),eggDrop(e,f-i));
       mina = min(mina,temp);
    }
    return mina;
}

int main() {
    int e,f;
    cin>>e>>f;
    cout<<eggDrop(e,f);
}
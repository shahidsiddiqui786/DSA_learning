#include<bits/stdc++.h>
using namespace std;

#define N 4

bool printratinmaze(int x,int y,int b[N][N]){
    if(x == N-1 && y == N-1){
        //print
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<'\n';
        }
        return true;
    }
    //move forward if alllowed
    if(x < (N-1) && b[x+1][y] != 0){
        b[x+1][y] = -1;
        if(printratinmaze(x+1,y,b)){
            return true;
        }
        b[x+1][y] = 1;
    }

    //move downward if allowed
    if(y < (N-1) && b[x][y+1] != 0){
         b[x][y+1] = -1;
        if(printratinmaze(x,y+1,b)){
            return true;
        }
        b[x][y+1] = 1;
    }
    return false;
}

int main(){

    int b[4][4];
    cout<<"enter 1 for free 0 for block cell";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>b[i][j];
        }
    }
    b[0][0] = -1;
    bool a = printratinmaze(0,0,b);
    if(!a) cout<<"impossible";
}
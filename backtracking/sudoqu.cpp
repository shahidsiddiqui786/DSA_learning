//sudoqu solver using backtracking
#include<bits/stdc++.h>
using namespace std;

bool isplaceable(int s[9][9],int r,int c,int num){
        // col and row
        for(int i=0;i<9;i++){
            if(s[r][i] == num || s[i][c] == num){
                return false;
            }
        }

        //for a sub - sudoqu
        int sx = (r/3)*3;
        int sy = (c/3)*3;
        for(int i = sx;i<(sx+3);i++){
            for(int j= sy;j<(sy+3);j++){
                if(s[i][j] == num){
                    return false;
                }
            }
        }

        return true;
}


bool solver(int s[9][9],int r,int c,int n){
    //base case
    if(r == n){
        //print sudoqu
        for(int i=0;i<9;i++){
            for(int j=0;j<n;j++){
                cout<<s[i][j]<<" ";
            }
            cout<<'\n';
        }
        return true;
    }
    //check if we cur row exhausted
    if(c == n){
       return solver(s,r+1,0,n);
    }

    //if already filled move on
    if(s[r][c] != 0){
        return solver(s,r,c+1,n);
    }

    for(int i=1;i<10;i++){
        if(isplaceable(s,r,c,i)){
            s[r][c] = i;

            bool isnext = solver(s,r,c+1,n);
            if(isnext){
                return true;
            }
            s[r][c] = 0;
        }
    }
    s[r][c] = 0;
    return false;
}

int main() {
    int n = 9;
    int s[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };
    solver(s,0,0,n);
}

#include<bits/stdc++.h>
using namespace std;


bool ratInMaze(char maze[10][10] ,int sol[][10],int i,int j,int m,int n){
    if(i == m && j == n){
          sol[m][n] = 1;
          //print the path
          for(int i=0;i<=m;i++){
              for(int j=0;j<=n;j++){
                  cout<<sol[i][j]<<" ";
              }
              cout<<'\n';
          }
          cout<<'\n';
          return true;
    }

    if(i>m || j>n){
        return false;
    }
    if(maze[i][j] == 'X'){
        return false;
    }

    sol[i][j] = 1;
    bool rgt = ratInMaze(maze,sol,i,j+1,m,n);
    bool dwt = ratInMaze(maze,sol,i+1,j,m,n);


    //backtrack
    sol[i][j] = 0;

    if(rgt || dwt){
        return true;
    }
    return false;
}


int main(){
    char maze[10][10] = {
        "0000",
        "X0X0",
        "000X",
        "0000",
    };
    int sol[10][10] = {0};
    int m = 4,n=4;

    bool ans = ratInMaze(maze,sol,0,0,m-1,n-1);

    if(!ans){
        cout<<"ok";
    }
}
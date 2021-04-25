//given n*n chess board need to place n queen in such configuration
//sothat  no one is harming any other.
//print posssible configuration
#include<bits/stdc++.h>
using namespace std;

//bitsets

int arr[100] = {-1};
int d1[200] = {-1};
int d2[200] = {-1};
int knightcheck[100][100];

void init(){
    memset(arr,-1,sizeof(arr));
    memset(d1,-1,sizeof(d1));
    memset(d2,-1,sizeof(d2));
    memset(knightcheck,-1,sizeof(knightcheck));
}


//can we place
bool isplaceable(int i,int j){

    //check for same col.
    if(arr[j] == 1){
        return false;
    }

    // check for left dig
    if(d1[(i-j)+99] == 1){
        return false;
    }
    
    // check for right dig
    if(d2[i+j] == 1){
        return false;
    }

    //last it conf safe
    return true;
}


bool isSafe(int i,int j){
      //queen move check
      if(!isplaceable(i,j)){
         return false;
      }
      //knight move check
      if(knightcheck[i][j] == 1){
          return false;
      }
      return true;
}

void placeknight(int i, int k, int n, int m, int num){
    if((i+2)<n){
        if((k+1) < m) knightcheck[i+2][k+1] = num;
        if((k-1) >= 0) knightcheck[i+2][k-1] = num;
    }
    if((k+2)<m){
        if((i+1) < n) knightcheck[i+1][k+2] = num;
        if((i-1) >= 0) knightcheck[i-1][k+2] = num;
    }
    if((i-2)>=0){
        if((k+1) < m) knightcheck[i-2][k+1] = num;
        if((k-1) >= 0) knightcheck[i-2][k-1] = num;
    }
    if((k-2)>=0){
        if((i+1) < n) knightcheck[i+1][k-2] = num;
        if((i-1) >= 0) knightcheck[i-1][k-2] = num;
    }
}

bool assignGuard(int b[][100],int i,int j,int n, int m){
     //base case
     if(i == n){
         //print
         int cnt = 0;
         for(int p=0;p<n;p++){
             for(int q=0;q<m;q++){
                  if(b[p][q] == 1){
                     cnt++;
                 }
             }
         }
          cout<<cnt<<'\n';
          for(int p=0;p<n;p++){
             for(int q=0;q<m;q++){
                 if(b[p][q] == 1){
                     cout<<"G"<<" ";
                 }
                 if(b[p][q] == -1){
                     cout<<"#"<<" ";
                 }
                 if(b[p][q] == 0){
                     cout<<"."<<" ";
                 }
             }
             cout<<'\n';
           }
         return true;
     }
     // go for ith row
     for(int k=j;k<m;k++){
         if(isSafe(i,k)){
            //place
            b[i][k] = 1;
            arr[k] = 1;
            d1[(i-k)+99] = 1;
            d2[(i+k)] = 1;
            placeknight(i,k,n,m,1);
             if(assignGuard(b,i+1,j,n,m)){
                 return true;
             }
             //unplace
              b[i][k] = 0;
            arr[k] = -1;
            d1[(i-k)+99] = -1;
            d2[(i+k)] = -1;
            placeknight(i,k,n,m,0);
         }
     }
     return assignGuard(b,i+1,j,n,m);
}

void divideRoom(int b[][100],int i,int j,int n, int m){
       if(i == n && j == m){
           return ;
       }
       for(int k=i;k<n;k++){
           if(b[k][0] == -1){
               divideRoom(b,i,j,k,m);
               divideRoom(b,k+1,j,n,m);
               return ;
           }
       }
       assignGuard(b,i,j,n,m);
}

int main(){
   
   int t;
   cin>>t;
   while(t--){
       init();
        int n,m;
        cin>>n>>m;
        char symbol;
        int board[100][100] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>symbol;
                if(symbol == '.'){
                    board[i][j] = 0; 
                }
                if(symbol == '#'){
                    board[i][j] = -1;
                }
            }
        }
        divideRoom(board,0,0,n,m);
   }
}
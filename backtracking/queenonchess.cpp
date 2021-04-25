//given n*n chess board need to place n queen in such configuration
//sothat  no one is harming any other.
//print posssible configuration
#include<bits/stdc++.h>
using namespace std;

//can we place
bool isplaceable(int b[][10],int i,int j,int n){
    //check for same col.
    for(int r =0;r<i;r++){
        if(b[r][j] == 1){
            return false;
        }
    }
    // check for left dig
    int p = i, q = j;
    while(p>=0 && q>=0){
        if(b[p][q]==1){
            return false;
        }
        p--;
        q--;
    }

    // check for right dig
    p = i, q = j;
    while(p>=0 && q<n){
       if(b[p][q] == 1){
           return false;
       }
       p--;
       q++;
    }
    //last it conf safe
    return true;
}

bool placeQ(int b[][10],int i,int n){
    if(i == n){
        //i.e. every queen is placed
        //print 
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(b[j][k] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<'\n';
        }
        cout<<'\n';
        return false;
    }
    //placing queen row by row
    for(int j=0;j<n;j++){
        if(isplaceable(b,i,j,n)){
            b[i][j] = 1;
             //try for next q
            bool ntq = placeQ(b,i+1,n);
            if(ntq){
                return true;
            }
            //it mean we need to backtrack
            b[i][j] = 0;
        }
    }
    return false;
}

int main(){
   
   int n;
   cin>>n;
   int board[10][10] = {0};
   int a = placeQ(board,0,n);
}
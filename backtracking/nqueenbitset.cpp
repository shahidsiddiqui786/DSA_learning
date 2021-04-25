//given n*n chess board need to place n queen in such configuration
//sothat  no one is harming any other.
//print posssible configuration
#include<bits/stdc++.h>
using namespace std;

//bitsets

int arr[10] = {-1};
int d1[19] = {-1};
int d2[19] = {-1};

//can we place
bool isplaceable(int b[][10],int i,int j,int n){

    //check for same col.
    if(arr[j] == 1){
        return false;
    }

    // check for left dig
    if(d1[(i-j)+9] == 1){
        return false;
    }
    
    // check for right dig
    if(d2[i+j] == 1){
        return false;
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
            arr[j] = 1;
            d1[(i-j)+9] = 1;
            d2[(i+j)] = 1;
             //try for next q
            bool ntq = placeQ(b,i+1,n);
            if(ntq){
                return true;
            }
            //it mean we need to backtrack
            b[i][j] = 0;
            arr[j] = -1;
            d1[(i-j)+9] = -1;
            d2[(i+j)] = -1;
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
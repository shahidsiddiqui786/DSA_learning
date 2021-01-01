// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

/*  A short Intro:- A Segment Tree is a data structure that allows answering range queries over
  an array effectively, and even can update the array in logarithmic time :) 

  Required:- Linear Amount of Memory Like array of size N would require 4N amount of
  Linear memory. So, It may be a Limitation.

  reference(https://cp-algorithms.com/data_structures/segment_tree.html)
*/

#include <bits/stdc++.h>
using namespace std;

// assuming n <= 10^3
int st[40000];

//building Sum Segement tree
void build(int a[],int v,int sl,int sr){
    if(sl == sr){
        st[v] = a[sl];
    }
    else{
        int sm = (sl+sr)/2;
        build(a,2*v,sl,sm);
        build(a,2*v+1,sm+1,sr);
        st[v] = st[2*v]+st[2*v+1];
    }
}

// For Printing (level wise traversal)
void printMySumSegmentTree(int v,int sl, int sr) {
     if(sl == sr){
         cout<<"sum("<<sl<<","<<sr<<") : "<<st[v]<<" ";
     }
     else{
         int sm = (sl+sr)/2;
        cout<<"sum("<<sl<<","<<sr<<") : "<<st[v]<<" ";
        printMySumSegmentTree(2*v,sl,sm);
        printMySumSegmentTree(2*v+1,sm+1,sr);
     }
}

// For a range of query like sum from l to r
int sum(int v,int sl, int sr, int l ,int r) {
       if(l>r){
           return 0;
       }
       if(l == sl && r == sr){
           return st[v];
       }
       int sm = (sl+sr)/2;
       return sum(2*v,sl,sm,l,min(r, sm)) + sum(2*v+1,sm+1,sr, max(l, sm+1), r);
}

// for updating values 
void update(int v,int sl, int sr,int pos, int new_val){
     if(sl == sr){
         st[v] = new_val;
     }
     else{
         int sm = (sl+sr)/2;
         if(pos <= sm){
             update(2*v,sl,sm,pos,new_val);
         }
         else{
             update(2*v+1,sm+1,sr,pos,new_val);
         }
         st[v] = st[2*v]+st[2*v+1];
     }
}

int main()
{
    int n;
    cin>>n;
    //enter array with more than five element to test.
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(arr,1,0,n-1);
    cout<<"Your segement tree:-"<<'\n';
    printMySumSegmentTree(1,0,n-1);
    cout<<'\n'<<sum(1,0,n-1,3,5);
    update(1,0,n-1,5,-5);
    cout<<'\n'<<sum(1,0,n-1,3,5);

    return 0;
}

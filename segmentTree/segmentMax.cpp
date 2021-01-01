// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

#include <bits/stdc++.h>
using namespace std;
int st[40000];

//building Max Segement tree
void build(int a[],int v,int sl,int sr){
    if(sl == sr){
        st[v] = a[sl];
    }
    else{
        int sm = (sl+sr)/2;
        build(a,2*v,sl,sm);
        build(a,2*v+1,sm+1,sr);
        st[v] = max(st[2*v],st[2*v+1]);
    }
}

void printMyMaxSegmentTree(int v,int sl, int sr) {
     if(sl == sr){
         cout<<"max("<<sl<<","<<sr<<") : "<<st[v]<<" ";
     }
     else{
         int sm = (sl+sr)/2;
        cout<<"max("<<sl<<","<<sr<<") : "<<st[v]<<" ";
        printMyMaxSegmentTree(2*v,sl,sm);
        printMyMaxSegmentTree(2*v+1,sm+1,sr);
     }

}

int maxm(int v,int sl, int sr, int l ,int r) {
       if(l>r){
           return INT_MIN;
       }
       if(l == sl && r == sr){
           return st[v];
       }
       int sm = (sl+sr)/2;
       return max(maxm(2*v,sl,sm,l,min(r, sm)) , maxm(2*v+1,sm+1,sr, max(l, sm+1), r));
}

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
         st[v] = max(st[2*v],st[2*v+1]);
     }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(arr,1,0,n-1);
    cout<<"Your segement tree:-"<<'\n';
    printMyMaxSegmentTree(1,0,n-1);
    update(1,0,n-1,5,-5);
    printMyMaxSegmentTree(1,0,n-1);
    return 0;
}

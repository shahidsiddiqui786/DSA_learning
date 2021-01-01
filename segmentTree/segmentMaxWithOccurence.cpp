// ************************ //
// * Shahid Siddiqui      * //                       
// * IIITA -IT- 2019-2023 * //                            
// ************************ //

#include <bits/stdc++.h>
using namespace std;
#define pb(a) push_back(a)
#define MP make_pair
#define pi pair<int, int>
#define ff first
#define ss second

pi st[40000];

pi combine(pi a, pi b){
    if(a.ff > b.ff){
        return a;
    }
    if(b.ff > a.ff){
        return b;
    }
    return MP(a.ff ,(a.ss + b.ss));
}

// building a max segment tree with the number of occurence of max element
void build(int a[],int v,int sl,int sr){
    if(sl == sr){
        st[v] = MP(a[sl],1);
    }
    else{
        int sm = (sl+sr)/2;
        build(a,2*v,sl,sm);
        build(a,2*v+1,sm+1,sr);
        st[v] = combine(st[2*v],st[2*v+1]);
    }
}

void printMyMaxPairSegmentTree(int v,int sl, int sr) {
     if(sl == sr){
         cout<<"max("<<sl<<","<<sr<<") : "<<st[v].ff<<" "<<st[v].ss;
     }
     else{
         int sm = (sl+sr)/2;
        cout<<"max("<<sl<<","<<sr<<") : "<<st[v].ff<<" "<<st[v].ss;
        printMyMaxPairSegmentTree(2*v,sl,sm);
        printMyMaxPairSegmentTree(2*v+1,sm+1,sr);
     }

}

pi get_max(int v,int sl, int sr, int l ,int r) {
       if(l>r){
           return MP(INT_MIN, 0);
       }
       if(l == sl && r == sr){
           return st[v];
       }
       int sm = (sl+sr)/2;
       return combine(get_max(2*v,sl,sm,l,min(r, sm)) ,get_max(2*v+1,sm+1,sr, max(l, sm+1), r));
}

void update(int v,int sl, int sr,int pos, int new_val){
     if(sl == sr){
         st[v] = MP(new_val,1);
     }
     else{
         int sm = (sl+sr)/2;
         if(pos <= sm){
             update(2*v,sl,sm,pos,new_val);
         }
         else{
             update(2*v+1,sm+1,sr,pos,new_val);
         }
         st[v] = combine(st[2*v],st[2*v+1]);
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
    printMyMaxPairSegmentTree(1,0,n-1);
    update(1,0,n-1,5,-5);
    printMyMaxPairSegmentTree(1,0,n-1);
    cout<<get_max(1,0,n-1,2,7).ff<<" "<<get_max(1,0,n-1,2,7).ss;
    return 0;
}

// Sqrt-decomposition based data structure

// Given an array a[0…n−1]
// , implement a data structure that allows to find the sum of the elements a[l…r] 
// for arbitrary l and r in O(n−−√) operations.

//references - https://cp-algorithms.com/data_structures/sqrt_decomposition.html

//edit:(Mo's algo apne kaam ki cheese bhi....:))


#include<bits/stdc++.h>
using namespace std;

vector<int> b;

void build(vector<int> a){
     
    // preprocessing
    int n = a.size();
    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks

    b.clear();
    b.resize(len);
    int z = 1;

    for (int i=0; i<n; ++i){
        if(i > (z*len-1)) z++;
         b[z-1] += a[i];
    }
       
}

void update(int n,int pos,int new_val,int old_val){

    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    int block = (pos+1) / len;
    cout<<block<<'\n';
    b[block] += (new_val - old_val);
}


int fetch(vector<int> a,int l,int r){
    
    int sum = 0;
    int n = a.size();
    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks

    int c_l = l / len,   c_r = r / len;

    if (c_l == c_r)
        for (int i=l; i<=r; ++i)
            sum += a[i];
    else {
        for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
            sum += a[i];
        for (int i=c_l+1; i<=c_r-1; ++i)
            sum += b[i];
        for (int i=c_r*len; i<=r; ++i)
            sum += a[i];
    }
    return sum;
}


int main(){
    // input data
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(a);
    cout<<"enter l and r"<<'\n';
    int l,r;

    cin>>l>>r;

    cout<<fetch(a,l,r);

    cout<<"want to update, enter pos, and new_val\n";

    int pos,new_val;
    cin>>pos>>new_val;

    update(n,pos,new_val,a[pos]);
    a[pos] = new_val;

    cout<<"after update ur value :-\n";
    cout<<fetch(a,l,r);
}
//given a string , we need to print all its permutations.
#include<bits/stdc++.h>
using namespace std;


//we basically start from 0 place of string and 
//put every possible letter there and then move
//to next and so on up to length of string
void permutate(string s, int i,int l){
    if(i == l){
        cout<<s<<" ";
        return;
    }
    // if we are in b/w the places permutate for every possible letter
    for(int j=i;j!=l;j++){
        swap(s[i],s[j]);
        permutate(s,i+1,l);
        //now we backtrack our swap to restore original string
        //so that we can permutate with the same logic to the next letter
        swap(s[i],s[j]);
    }
}


int main() {
    string st;
    cin>>st;
    permutate(st,0,st.length());
}
#include<bits/stdc++.h>
using namespace std;

set<string> printSubset(string s,string op,set<string> &st){
    if(s.length() == 0){
        st.insert(op);
        return st;
    }
    string op1,op2;
    op1 = op;
    op2 = op;
    op2 += s[0];
    s.erase(s.begin());
    st = printSubset(s,op1,st);
    st = printSubset(s,op2,st);
    return st;
}


int main() {
    
    string s;
    cin>>s;
    string op;
    set<string> st;
    st = printSubset(s,op,st);
    for(auto i : st){
        cout<<i<<" ";
    }
}
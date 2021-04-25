#include<bits/stdc++.h>
using namespace std;

void printSubset(string s,string op){
    if(s.length() == 0){
        cout<<op<<" ";
        return ;
    }
    string op1,op2;
    op1 = op;
    op2 = op;
    op2 += s[0];
    s.erase(s.begin());
    printSubset(s,op1);
    printSubset(s,op2);
}


int main() {
    
    string s;
    cin>>s;
    string op;
    printSubset(s,op);
}
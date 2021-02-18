#include<bits/stdc++.h>
using namespace std;

void printPermu(string s,string op){
    if(s.length() == 1){
        op += s[0];
        cout<<op<<" ";
        return;
    }
    for(int i=0;i<s.length();i++){
        string ip1,op1;
        ip1 = s;
        op1 = op;
        op1 += ip1[i];
        ip1.erase(ip1.begin()+i);
        printPermu(ip1,op1);
    }
    return ;
}


int main() {
    
    string s;
    cin>>s;
    string op;
    printPermu(s,op);
}
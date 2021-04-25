#include<bits/stdc++.h>
using namespace std;

void printPermu(string s,string op){
    if(s.length() == 0){
        cout<<op<<" ";
        return;
    }
    string op1 ,op2;
    op1 += op;
    op2 += op;
    int dig = s[0];
    if(dig>=97 && dig <=122 || dig>=65 && dig<=90){
        op1.push_back(s[0]);
        if(isupper(s[0])){
            op2.push_back(tolower(s[0]));
        }
        else{
            op2.push_back(toupper(s[0]));
        }
        s.erase(s.begin() + 0);
        printPermu(s,op1);
        printPermu(s,op2);
    }
    else{
        op += s[0];
        s.erase(s.begin() + 0);
        printPermu(s,op);
    }
   
    return ;
}


int main() {
    
    string s;
    cin>>s;
    string op;
    printPermu(s,op);
}
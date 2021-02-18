#include<bits/stdc++.h>
using namespace std;

void generatecomb(int o,int c,string str){
    if(o == 0 && c == 0){
        cout<<str<<'\n';
        return;
    }
    if(o == c){
      str += '(';
      generatecomb(o-1,c,str);
      return;
    }
    else if(o == 0 && c > 0){
       str += ')';
       generatecomb(o,c-1,str);
       return;
    }
    string s1,s2;
       s1 += str;
       s2 += str;
       s1 += ')';
       s2 += '(';
       generatecomb(o,c-1,s1);
       generatecomb(o-1,c,s2);
       return;
}


int main() {
    
    int n;
    cin>>n;
    string op;
    generatecomb(n,n,op);
}
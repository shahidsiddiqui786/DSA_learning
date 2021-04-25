#include<bits/stdc++.h>
using namespace std;

bool iszero(string s){
    bool asd = (s[0] == '1');
    for(int i=1;i<s.length();i++){
        if(s[i] == '0') asd = false;
        if(asd && s[i] == '1'){
            return false;
        }
        if(s[i] == '1') asd = true;
    }
    return true;
}

bool isone(string s){
    bool asd = (s[0] == '0');
        for(int i=1;i<s.length();i++){
            if(s[i] == '1') asd = false;
            if(asd && s[i] == '0'){
                return false;
            }
            if(s[i] == '0') asd = true;
        }
        return true;
}

bool iszerone(string s){
    int zero , one ;
    bool zs=(s[s.length()-1] == '0'), os=(s[0] == '1');
    for(int i=s.length()-2;i>=0;i--){
            if(s[i] == '1') zs = false;
            if(zs && s[i] == '0'){
                zero = i;
                break;
            }
            if(s[i] == '0') zs = true;
    }

    for(int i=1;i<s.length();i++){
         if(s[i] == '0') os = false;
            if(os && s[i] == '1'){
                one = i;
                break;
            }
            if(s[i] == '1') os = true;
    }

    if(iszero(s.substr(0,zero+1)) && isone(s.substr(one+1))){
         return true;
    }
    return false;
}

void solve(){
      string str;
       cin>>str;

       if(iszero(str)){
           cout<<"YES"<<'\n';
           return ;
       }
       if(isone(str)){
           cout<<"YES"<<'\n';
           return ;
       }

       if(iszerone(str)){
           cout<<"YES"<<'\n';
           return ;
       }
        cout<<"NO"<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
}
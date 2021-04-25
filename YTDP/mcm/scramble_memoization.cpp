// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled  
// form of S1.
// Scrambled string: 
// Given string str, we can represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
// Note: Srambled string is not same as an Anagram

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> dp;

bool scrambled(string a, string b){
    if(a.compare(b) == 0){
        return true;
    }
    int n = a.length();
    if(n <= 1){
        return false;
    }

    string key = a;
    key.push_back(' ');
    key.append(b);

    if(dp[key]){
        return dp[key];
    }

    bool flag = false;

    for(int i=1;i<n;i++){
        bool a1 = scrambled(a.substr(0,i),b.substr(n-i,i));
        bool a2 = scrambled(a.substr(i,n-i),b.substr(0,n-i));
        bool b1 = scrambled(a.substr(0,i),b.substr(0,i));
        bool b2 = scrambled(a.substr(i,n-i),b.substr(i,n-i));
        if((a1 && a2 ) || (b1 && b2)){
            flag = true;
            break;
        }
    }
    return dp[key] = flag;
}


int main(){
    string a,b;
    cin>>a>>b;
    if(a.length() != b.length()){
        cout<<"false";
        return 0;
    }
    else if(a.length()==0 && b.length()==0){
        cout<<"true";
        return 0;
    }
    else{
        cout<<scrambled(a,b);
    }
}
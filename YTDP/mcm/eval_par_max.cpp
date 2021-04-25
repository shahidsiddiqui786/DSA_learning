//Warning!!  This is expert level problem


// Count the number of ways we can parenthesize the expression so that the value of expression
// evaluates to true. 
// Let the input be in form of two
// arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

#include<bits/stdc++.h>
using namespace std;

int par_count(string s, int i,int j,int isTrue){
    if(i > j){
        return false;
    }
    if(i == j){
        if(isTrue){
           return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    int ans = 0;
    for(int k=i+1;k<j;k = k+2){
        int lt = par_count(s,i,k-1,1);
        int lf = par_count(s,i,k-1,0);
        int rt = par_count(s,k+1,j,1);
        int rf = par_count(s,k+1,j,0);

        if(s[k] == '^'){
            if(isTrue){
               ans += lt*rf+lf*rt;
            }
            else{
               ans += lt*rt+lf*rf;   
            }
        }
        else if(s[k] == '|'){
            if(isTrue){
               ans += lt*rf+lf*rt+lt*rt;
            }
            else{
               ans += lf*rf;   
            }
        }
        else if(s[k] == '&'){
              if(isTrue){
                 ans += lt*rt;
                }
                else{
                ans += lf*rf+lt*rf+lf*rt;   
                }
        }
    }
    return ans;
}

int main() {
     string symbols;
    string operators;
    cin>>symbols;
    cin>>operators;
    string s;
    int j = 0;
 
    for (int i = 0; i < symbols.length(); i++) 
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }
     
    // We obtain the string  T|T&F^T
    int n = s.length();
    cout<<par_count(s,0,n-1,1);
}
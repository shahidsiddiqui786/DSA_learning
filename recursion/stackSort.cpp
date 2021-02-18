#include<bits/stdc++.h>
using namespace std;

void insertSort(stack<int> &s,int p){
    if(s.size() == 0){
        s.push(p);
        return;
    }
    if(s.top() > p){
        int po = s.top();
        s.pop();
        insertSort(s,p);
        s.push(po);
        return ;
    }
    else{
        s.push(p);
        return ;
    }
}

void recurSort(stack <int> &s){
     if(s.size() == 1){
         return ;
     }
     int p = s.top();
     s.pop();
     recurSort(s);
     insertSort(s,p);
     return ;
}

int main() {
    
    stack<int> st;
    st.push(78);
    st.push(2);
    st.push(23);
    st.push(33);
    st.push(56);
    st.push(38);
    recurSort(st);
    while(st.size() != 0){
        cout<<st.top()<<" ";
        st.pop();
    }
}
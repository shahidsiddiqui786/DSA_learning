#include<bits/stdc++.h>
using namespace std;

void insertRev(stack<int> &s,int p){
    if(s.size() == 0){
        s.push(p);
        return;
    }
    int po = s.top();
    s.pop();
    insertRev(s,p);
    s.push(po);
}

void recurRev(stack<int> &s){
    if(s.size() == 0){
        return;
    }
    int p = s.top();
    s.pop();
    recurRev(s);
    insertRev(s,p);
    return;
}


int main() {
    
    stack<int> st;
    st.push(78);
    st.push(2);
    st.push(23);
    st.push(33);
    st.push(56);
    st.push(38);
    recurRev(st);
    while(st.size() != 0){
        cout<<st.top()<<" ";
        st.pop();
    }
}
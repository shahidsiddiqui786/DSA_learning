#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s,int pos){
    if(s.size() == pos){
        s.pop();
        return;
    }
    int p = s.top();
    s.pop();
    deleteMiddle(s,pos);
    s.push(p);
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
    deleteMiddle(st,(st.size()/2+1));
    while(st.size() != 0){
        cout<<st.top()<<" ";
        st.pop();
    }
}